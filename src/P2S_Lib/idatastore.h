#pragma once

#include "p2slib.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {

/**
 * @name    IDataStore
 * @brief   Interface abstraction for database management
 */
class P2S_LIBSHARED_EXPORT IDataStore
{
public:
    virtual void Connect(const std::string& host, const uint16_t& port) = 0;
    virtual void Put(std::string key, std::vector<nlohmann::json> changes) = 0;
    virtual std::vector<nlohmann::json> Get(std::string key) = 0;
    virtual std::vector<nlohmann::json> Get(std::string key, std::vector<std::string> ids ) = 0;
    virtual std::vector<nlohmann::json> Meta(std::string key) = 0;
    virtual ~IDataStore() = default;
};

class DataStoreException : public std::runtime_error
{
public:
  DataStoreException(const std::string & err) : std::runtime_error(err) {}
};

using IDataStorePtr = std::shared_ptr<IDataStore>;

}
}
