#pragma once

#include "p2slib.h"
#include "iresponse.h"
#include "../../dependencies/json.hpp"

namespace P2S {
namespace Lib {

/**
 * @name    OptionsResponse
 * @brief   implementation of the response for Options
 */
class P2S_LIBSHARED_EXPORT IOptionsResponse : public IResponse
{
public:
    virtual std::string Serialize() = 0;
};

/**
 * @name    OptionsRPCResponse
 * @brief   implementation of the rpc path for response on Options
 */
class P2S_LIBSHARED_EXPORT OptionsRPCResponse : public IOptionsResponse
{
public:
    virtual std::string Serialize();
};

}
}
