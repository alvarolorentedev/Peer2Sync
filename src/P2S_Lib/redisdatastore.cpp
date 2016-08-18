#include "redisdatastore.h"

using namespace P2S::Lib;
using namespace cpp_redis;
using namespace std;

using json = nlohmann::json;

void RedisDataStore::Connect(const string& host, const uint16_t& port)
{
    client.connect(host, port);
}

void RedisDataStore::Put(string key, std::vector<json> changes)
{
    client.setnx(key, "{}");
    json collection = json::parse(this->GetSync(key));
    for(auto change : changes){
        if(change["_delete"].get<bool>())
        {
            collection.erase(change["_id"].get<string>());
            continue;
        }
        else if(collection.count("_id") == 0 || collection["_id"]["_mtime"].get<time_t>() < change["_mtime"].get<time_t>())
        {
            collection[change["_id"].get<string>()] = change;
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

