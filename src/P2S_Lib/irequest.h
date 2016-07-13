#pragma once

#include "p2s_lib_global.h"

namespace P2S {
namespace Lib {

class P2S_LIBSHARED_EXPORT IRequest
{
public:
    virtual void Parse(const std::string& content) = 0;
    virtual ~IRequest() = default;
};

}
}
