#pragma once

#include "p2slib.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {

class P2S_LIBSHARED_EXPORT JSonRPCValidator
{
    std::vector<std::function<bool(nlohmann::json)>> rules =
    {
        [](nlohmann::json value){ return value["jsonrpc"] == "2.0"; }
    };
public:
    bool IsValid(nlohmann::json object);
};

}
}
