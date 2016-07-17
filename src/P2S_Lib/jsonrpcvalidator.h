#pragma once

#include "p2slib.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {

/**
 * @name    JSonRPCValidator
 * @brief   validation for correct creation or parsing of packages
 */
class P2S_LIBSHARED_EXPORT JSonRPCValidator
{
    std::vector<std::function<bool(nlohmann::json)>> rules;
protected:
    JSonRPCValidator(std::vector<std::function<bool(nlohmann::json)>> rulesParam) : rules(rulesParam) {}
public:
    JSonRPCValidator() = delete;
    bool IsValid(nlohmann::json object);
};

/**
 * @name    JSonRPCValidator
 * @brief   validation for correct parsing of JSON-RPC 2.0 packages
 */
class P2S_LIBSHARED_EXPORT JSonRPCRequestValidator : public JSonRPCValidator
{
public:
    JSonRPCRequestValidator() : JSonRPCValidator(
    {
        [](nlohmann::json value){ return value["jsonrpc"] == "2.0"; },
        [](nlohmann::json value){ return value.find("method") != value.end(); }
    }) {};
};

/**
 * @name    JSonRPCValidator
 * @brief   validation for correct generation of JSON-RPC 2.0 packages
 */
class P2S_LIBSHARED_EXPORT JSonRPCResponseValidator : public JSonRPCValidator
{
public:
    JSonRPCResponseValidator() : JSonRPCValidator(
    {
        [](nlohmann::json value){ return value["jsonrpc"] == "2.0"; },
        [](nlohmann::json value){ return
                                    (value.find("result") == value.end() && value.find("error") != value.end())
                                ||  (value.find("result") != value.end() && value.find("error") == value.end());
                                },
        [](nlohmann::json value){
                                if(value.find("error") != value.end())
                                    return value.find("error").value().is_object();
                                return true;
                                }
    }) {};
};

}
}
