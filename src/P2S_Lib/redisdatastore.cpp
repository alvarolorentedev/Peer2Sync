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
    mutex m;
    unique_lock<std::mutex> lock(m);
    condition_variable sync;
    string result;
    bool gotResult = false;
    client.get(key, [&] (cpp_redis::reply& reply) {
        if(reply.is_error() || reply.is_null())
            throw("error on during getting key");
        result = reply.as_string();
        gotResult = true;
        sync.notify_one();
      });
    client.commit();
    sync.wait(lock, [&]() { return gotResult; });
    return result;
}

