#include "redisdatastore.h"

using namespace P2S::Lib;
using namespace cpp_redis;
using namespace std;

void RedisDataStore::Connect(const string& host, const uint16_t& port)
{
    client.connect(host, port);
}

void RedisDataStore::Put(string key, std::vector<nlohmann::json> changes)
{
    //client.setnx(key,changes);
    throw("Not Implemented Exception");
}

vector<nlohmann::json> RedisDataStore::Get(string key, bool all, vector<string> ids)
{
    throw("Not Implemented Exception");
}

vector<nlohmann::json> RedisDataStore::Meta(string key)
{
    throw("Not Implemented Exception");
}
