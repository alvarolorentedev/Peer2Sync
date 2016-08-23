#pragma once

#include<iresponse.h>

namespace P2S {
namespace App {

/**
 * @name    HTTPMethod
 * @brief   enum with types of Http methods
 */
enum class HTTPMethod
{
    POST,
    OPTIONS
};

/**
 * @name    IServer
 * @brief   Interface abstraction of the server
 */
class IServer
{
public:
    virtual void Subscribe(const std::string& path, const HTTPMethod& method,const std::function<Lib::IResponsePtr(std::string)>& func) = 0;
    virtual void Subscribe(const std::string& path, const std::function<Lib::IResponsePtr(std::string, HTTPMethod)>& func) = 0;
    virtual void Start(const int& port) = 0;
    virtual ~IServer() = default;
};


using IServerPtr = std::shared_ptr<IServer>;

}
}


