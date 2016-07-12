#ifndef SERVER_H
#define SERVER_H

#include "IServer.h"
#include "../../dependencies/crow_all.h"

namespace P2S {
namespace App {

class CrowServer : public IServer
{
private:
    crow::SimpleApp app;
public:
    CrowServer() = default;
    virtual void Subscribe(const std::string& path, std::function<void()>& function);
    virtual void Start(const int& port);
};

}
}

#endif // SERVER_H
