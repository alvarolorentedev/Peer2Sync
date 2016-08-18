#pragma once

#include <idatastore.h>
#include "irpcmethod.h"

namespace P2S {
namespace App {
/**
 * @name    DataStoreMeta
 * @brief   Meta method from RPC, it retrieves the array of ids and time changed
 */
class DataStoreMeta : public IRpcMethod
{
    P2S::Lib::IDataStorePtr datastore;
public:
    DataStoreMeta(const P2S::Lib::IDataStorePtr& dstore);
    virtual std::string Execute(const nlohmann::json& params);
};

}
}
