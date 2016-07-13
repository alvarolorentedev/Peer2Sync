#pragma once

#include<iresponse.h>

namespace P2S {
namespace App {

enum class HTTPMethod
{
    POST
};

class IServer
{
public:
    virtual void Subscribe(const std::string& path, const HTTPMethod& method,const std::function<Lib::IResponsePtr(std::string)>& func) = 0;
    virtual void Start(const int& port) = 0;
    virtual ~IServer() = default;
};

}
}


