#pragma once

#include <jsonrpcresponse.h>
#include<idatastore.h>
#include "IServer.h"
#include "../../dependencies/json.hpp"
#include "irpcmethod.h"

namespace P2S {
namespace App {

/**
 * @name    RpcMethods
 * @brief   Implementation of the holding class of the rpc methods
 */
class RpcMethods
{
    P2S::Lib::IDataStorePtr datastore;
    std::map<std::string, P2S::App::IRpcMethodPtr> paths;
public:
    RpcMethods(const P2S::App::IServerPtr& server, const P2S::Lib::IDataStorePtr& dstore);
private:
    P2S::Lib::IResponsePtr Post(const std::string& req);
    P2S::Lib::IResponsePtr Options();
};

}
}
