#pragma once

#include "p2slib.h"

namespace P2S {
namespace Lib {

class P2S_LIBSHARED_EXPORT IResponse
{
public:
    virtual std::string Serialize() = 0;
    virtual ~IResponse() = default;
};

using IResponsePtr = std::shared_ptr<IResponse>;

}
}

