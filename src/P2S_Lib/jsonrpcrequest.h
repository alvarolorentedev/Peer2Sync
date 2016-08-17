#pragma once

#include "p2slib.h"
#include "jsonrpcvalidator.h"
#include "irequest.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {

/**
 * @name    JsonRpcRequest
 * @brief   implementation of the request for JSON-RPC 2.0
 */
class P2S_LIBSHARED_EXPORT JsonRpcRequest : public IRequest
{
    nlohmann::json content;
    JSonRPCRequestValidator validator;
public:
    virtual void Deserialize(const std::string& rawContent);
    std::string GetMethod();
    nlohmann::json GetParams();
    std::string GetId();
};


class RequestParseException : public std::runtime_error
{
public:
  RequestParseException(const std::string & err) : std::runtime_error(err) {}
};

}
}
