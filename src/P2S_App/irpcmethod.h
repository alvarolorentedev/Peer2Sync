#pragma once

#include<iresponse.h>
#include "../../dependencies/json.hpp"

namespace P2S {
namespace App {


/**
 * @name    IRpcMethod
 * @brief   Interface abstraction of the methods supported in RPC
 */
class IRpcMethod
{
public:
    virtual std::string Execute(const nlohmann::json& params) = 0;
};


using IRpcMethodPtr = std::shared_ptr<IRpcMethod>;

}
}
