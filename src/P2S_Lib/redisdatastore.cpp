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
                collection.erase("_id");
                continue;
            }
            if(collection.count("_id") == 0 || collection["_id"]["_mtime"].get<time_t>() < change["_mtime"].get<time_t>())
            {
                collection["_id"] = change;
                continue;
            }
        }
        client.set(key, collection.dump());
        client.commit();
      });
    client.commit();
}

vector<json> RedisDataStore::Get(string key, bool all, vector<string> ids)
{
    throw("Not Implemented Exception");
}

vector<json> RedisDataStore::Meta(string key)
{
    throw("Not Implemented Exception");
}
