#pragma once

#include "p2slib.h"

namespace P2S {
namespace Lib {

/**
 * @name    IRequest
 * @brief   Interface abstraction for request comming to server
 */
class P2S_LIBSHARED_EXPORT IRequest
{
public:
    virtual void Deserialize(const std::string& content) = 0;
    virtual ~IRequest() = default;
};

using IRequestPtr = std::shared_ptr<IRequest>;

}
}
