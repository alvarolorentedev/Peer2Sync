#pragma once

#include "p2slib.h"
#include "jsonrpcvalidator.h"
#include "irequest.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {

class P2S_LIBSHARED_EXPORT JsonRpcRequest : public IRequest
{
    nlohmann::json content;
    JSonRPCValidator validator;
public:
    virtual void Parse(const std::string& rawContent);
};


class RequestParseException : public std::runtime_error
{
public:
  RequestParseException(const std::string & err) : std::runtime_error(err) {}
};

}
}
