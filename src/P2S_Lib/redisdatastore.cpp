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
    json collection;
    client.setnx(key, "{}");
    client.get(key, [&changes, &collection] (cpp_redis::reply& reply) {
        collection = json::parse(reply.as_string());
        for(auto change : changes){
            if(change["_delete"].get<bool>())
            {
                collection.erase("_id");
                continue;
            }
            auto var = collection["_id"];
            auto timeObject = var["_mtime"].get<time_t>();
            auto timeChange = change["_id"].get<time_t>();
            if(timeChange > timeObject )
                collection["_id"] = change;
        }
      });
    client.set(key, collection.dump());
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
