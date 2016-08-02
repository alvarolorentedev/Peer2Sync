#pragma once

#include <jsonrpcresponse.h>
#include "IServer.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace App {


class RpcMethods
{
    std::map<std::string, std::function<P2S::Lib::IResponsePtr(nlohmann::json)>> paths =
    {
        { "datastorePut" , nullptr }
    };
public:
    RpcMethods(const P2S::App::IServerPtr& server);
};

}
}
