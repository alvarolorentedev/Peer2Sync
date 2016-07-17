#pragma once

#include "p2slib.h"
#include "jsonrpcvalidator.h"
#include "iresponse.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {


class P2S_LIBSHARED_EXPORT JsonRpcResponse : public IResponse
{
private:
    JSonRPCRequestValidator validator;
protected:
    nlohmann::json content;
    JsonRpcResponse(uint32_t id);
public:
    JsonRpcResponse() = delete;
    virtual std::string Serialize();
};

class P2S_LIBSHARED_EXPORT  ValidJsonRpcResponse : public JsonRpcResponse
{
public:
    ValidJsonRpcResponse(std::string result, uint16_t id);
};

class P2S_LIBSHARED_EXPORT  ErrorJsonRpcResponse : public JsonRpcResponse
{
public:
    ErrorJsonRpcResponse(int code, std::string message, uint16_t id, std::string data = "");
};

class ResponseException : public std::runtime_error
{
public:
  ResponseException(const std::string & err) : std::runtime_error(err) {}
};

}
}
