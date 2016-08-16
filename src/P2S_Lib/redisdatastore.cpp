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
    client.get(key, [=] (cpp_redis::reply& reply) {
        json collection = json::parse(reply.as_string());
        for(auto change : changes){
            if(change["_delete"].get<bool>())
            {
                collection.erase(change["_id"].get<string>());
                continue;
            }
            if(collection.count("_id") == 0 || collection["_id"]["_mtime"].get<time_t>() < change["_mtime"].get<time_t>())
            {
                collection[change["_id"].get<string>()] = change;
                continue;
            }
        }
        client.set(key, collection.dump());
        client.commit();
      });
    client.commit();
}

vector<json> RedisDataStore::Get(string key)
{
    std::mutex m;
    std::unique_lock<std::mutex> lock(m);
    std::condition_variable cond_var;
    vector<json> result;
    bool gotResult = false;
    client.get(key, [&] (cpp_redis::reply& reply) {
        json collection = json::parse(reply.as_string());
        for (auto& element : collection)
          result.push_back(element);
        gotResult = true;
        cond_var.notify_one();
      });
    client.commit();
    cond_var.wait(lock, [&]() { return gotResult; });
    return result;

}

vector<json> RedisDataStore::Get(string key, vector<string> ids)
{
    std::mutex m;
    std::unique_lock<std::mutex> lock(m);
    std::condition_variable cond_var;
    vector<json> result;
    bool gotResult = false;
    client.get(key, [&] (cpp_redis::reply& reply) {
        json collection = json::parse(reply.as_string());
        for (auto& id : ids)
          result.push_back(collection[id]);
        gotResult = true;
        cond_var.notify_one();
      });
    client.commit();
    cond_var.wait(lock, [&]() { return gotResult; });
    return result;
}

vector<json> RedisDataStore::Meta(string key)
{
    std::mutex m;
    std::unique_lock<std::mutex> lock(m);
    std::condition_variable cond_var;
    vector<json> result;
    bool gotResult = false;
    client.get(key, [&] (cpp_redis::reply& reply) {
        json collection = json::parse(reply.as_string());
        for (auto& element : collection){
            json local;
            local["id"] = element["_id"];
            local["mtime"] = element["_mtime"];
            result.push_back(local);
        }
        gotResult = true;
        cond_var.notify_one();
      });
    client.commit();
    cond_var.wait(lock, [&]() { return gotResult; });
    return result;
}

