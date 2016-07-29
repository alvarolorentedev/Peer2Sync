#pragma once

#include "p2slib.h"
#include "idatastore.h"
#include <cpp_redis/cpp_redis>

namespace P2S {
namespace Lib {

/**
 * @name    RedisDataStore
 * @brief   implementation of database connection and methods using redis
 */
class P2S_LIBSHARED_EXPORT RedisDataStore : public IDataStore
{
    cpp_redis::redis_client client;
public:
    virtual void Connect(const std::string& host, const uint16_t& port);
    virtual void Set(std::string key, std::string value) = 0;
    virtual std::string Get(std::string key) = 0;
};

}
}
