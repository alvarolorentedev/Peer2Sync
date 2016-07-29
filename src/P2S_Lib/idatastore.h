#pragma once

#include "p2slib.h"

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
    virtual void Set(std::string key, std::string value) = 0;
    virtual std::string Get(std::string key) = 0;
    virtual ~IDataStore() = default;
};

using IDataStorePtr = std::shared_ptr<IDataStore>;

}
}
