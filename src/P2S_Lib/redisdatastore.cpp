#include "redisdatastore.h"

using namespace P2S::Lib;
using namespace cpp_redis;
using namespace std;

void RedisDataStore::Connect(const string& host, const uint16_t& port)
{
    client.connect(host, port);
}

string RedisDataStore::Get(string key)
{
    throw("Not Implemented Exception");
}

void RedisDataStore::Set(string key, string value)
{
    throw("Not Implemented Exception");
}
