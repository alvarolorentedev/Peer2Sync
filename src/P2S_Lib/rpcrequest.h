#pragma once

#include "p2s_lib_global.h"
#include "irequest.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {

class P2S_LIBSHARED_EXPORT RPCRequest : public IRequest
{
    nlohmann::json content;
public:
    virtual void Parse(const std::string& rawContent);

};

}
}
