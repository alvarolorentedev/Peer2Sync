#pragma once

#include <idatastore.h>
#include "irpcmethod.h"

namespace P2S {
namespace App {
/**
 * @name    DataStorePut
 * @brief   Put method from RPC, it adds or updates a collection passed through the call
 */
class DataStorePut : public IRpcMethod
{
    P2S::Lib::IDataStorePtr datastore;
public:
    DataStorePut(const P2S::Lib::IDataStorePtr& dstore);
    virtual Lib::IResponsePtr Execute(const nlohmann::json& params);
};

}
}
