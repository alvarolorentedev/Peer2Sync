#pragma once

#include "IServer.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"
#include "../../dependencies/crow_all.h"
#pragma GCC diagnostic warning "-Wunused-parameter"

namespace P2S {
namespace App {

/**
 * @name    CrowServer
 * @brief   Implementation of IServer with crow framework
 */
class CrowServer : public IServer
{
private:
    crow::SimpleApp app;
    std::map<P2S::App::HTTPMethod, crow::HTTPMethod> methods = { {P2S::App::HTTPMethod::POST, crow::HTTPMethod::POST} };
public:
    virtual void Subscribe(const std::string& path, const HTTPMethod& method,const std::function<Lib::IResponsePtr(std::string)>& func);
    virtual void Start(const int& port);
};

}
}

