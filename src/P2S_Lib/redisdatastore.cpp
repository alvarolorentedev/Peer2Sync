#include "redisdatastore.h"

using namespace P2S::Lib;
using namespace cpp_redis;
using namespace std;

using json = nlohmann::json;

/* Helper Functions */

bool Exist(string id, json collection)
{
    return collection.count(id) != 0;
}

bool ShouldDelete(json object)
{
    return object.count("_delete") !=0 && object["_delete"].get<bool>();
}

bool IsNewer(json base, json compare)
{
    return base["_mtime"].get<uint64_t>() < compare["_mtime"].get<uint64_t>();
}

/* Class Functions */

void RedisDataStore::Connect(const string& host, const uint16_t& port)
{
    client.connect(host, port);
}

void RedisDataStore::Put(string key, std::vector<json> changes)
{
    client.setnx(key, "{}");
    json collection = json::parse(this->GetSync(key));
    for(auto change : changes){
        auto changeId = change["_id"].get<string>();
        if(Exist(changeId,collection) && ShouldDelete(change))
        {
            collection.erase(changeId);
            continue;
        }
        else if(!Exist(changeId,collection) || IsNewer(collection[changeId], change))
        {
            collection[changeId] = change;
            continue;
        }
    }
    client.set(key, collection.dump());
    client.commit();
}

vector<json> RedisDataStore::Get(string key)
{
    vector<json> result;
    json collection = json::parse(this->GetSync(key));
    for (auto& element : collection)
      result.push_back(element);
    return result;

}

vector<json> RedisDataStore::Get(string key, vector<string> ids)
{
    vector<json> result;
    json collection = json::parse(this->GetSync(key));
    for (auto& id : ids)
      result.push_back(collection[id]);
    return result;
}

vector<json> RedisDataStore::Meta(string key)
{
    vector<json> result;
    json collection = json::parse(this->GetSync(key));
    for (auto& element : collection){
        json local;
        local["id"] = element["_id"];
        local["mtime"] = element["_mtime"];
        result.push_back(local);
    }
    return result;
}

string RedisDataStore::GetSync(string key)
{
        bool badReply = false;
        mutex m;
        unique_lock<std::mutex> lock(m);
        condition_variable sync;
        string result;
        bool endLambda = false;
        client.get(key, [&] (cpp_redis::reply& reply) throw(DataStoreException) {
            if(!reply.is_string())
                badReply = true;
            else
                result = reply.as_string();
            endLambda = true;
            sync.notify_one();
          });
        client.commit();
        sync.wait(lock, [&]() { return endLambda; });
        if(badReply)
            throw DataStoreException("error on during getting key");
        return result;
}

