#pragma once

#include <idatastore.h>
#include "irpcmethod.h"

namespace P2S {
namespace App {
/**
 * @name    DataStoreGet
 * @brief   Get method from RPC, it retrieves the information of the collection passed through the call
 */
class DataStoreGet : public IRpcMethod
{
    P2S::Lib::IDataStorePtr datastore;
public:
    DataStoreGet(const P2S::Lib::IDataStorePtr& dstore);
    virtual Lib::IResponsePtr Execute(const nlohmann::json& params);
};

}
}
