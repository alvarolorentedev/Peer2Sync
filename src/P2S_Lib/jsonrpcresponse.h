#pragma once

#include "p2slib.h"
#include "jsonrpcvalidator.h"
#include "iresponse.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {

class P2S_LIBSHARED_EXPORT JsonRpcResponse : public IResponse
{
    nlohmann::json content;
    JSonRPCRequestValidator validator;
public:
    virtual std::string Serialize();
};

class ResponseException : public std::runtime_error
{
public:
  ResponseException(const std::string & err) : std::runtime_error(err) {}
};

}
}
