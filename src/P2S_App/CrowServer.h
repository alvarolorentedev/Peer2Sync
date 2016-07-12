#ifndef SERVER_H
#define SERVER_H

#include <map>
#include "IServer.h"
#include "../../dependencies/crow_all.h"

namespace P2S {
namespace App {

class CrowServer : public IServer
{
private:
    crow::SimpleApp app;
    std::map<P2S::App::HTTPMethod, crow::HTTPMethod> methods = { {P2S::App::HTTPMethod::POST, crow::HTTPMethod::POST} };
public:
    CrowServer() = default;
    virtual void Subscribe(const std::string& path, const HTTPMethod& method,const std::function<void()>& func);
    virtual void Start(const int& port);
};

}
}

#endif // SERVER_H
