#pragma once

#include "p2s_lib_global.h"
#include "irequest.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {

class P2S_LIBSHARED_EXPORT RPCRequest : public IRequest
{
    nlohmann::json content;
    std::vector<std::function<bool(nlohmann::json)>> rules =
    {
        [](nlohmann::json value){ return value["jsonrpc"] == "2.0"; }
    };
public:
    virtual void Parse(const std::string& rawContent);
private:
    bool Validate(nlohmann::json object);
};


class RequestParseException : public std::runtime_error
{
public:
  RequestParseException(const std::string & err) : std::runtime_error(err) {}
};

}
}
