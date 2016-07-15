#include "jsonrpcvalidator.h"

using namespace P2S::Lib;
using json = nlohmann::json;

bool JSonRPCValidator::IsValid(json object)
{
    for (auto const &rule : rules)
        if(!rule(object))
            return false;
    return true;
}

