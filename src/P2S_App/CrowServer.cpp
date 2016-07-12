#include "CrowServer.h"

using namespace P2S::App;

void CrowServer::Subscribe(const std::string& path, std::function<void()>& function)
{
    app.route_dynamic(std::string(path))([](){ return "Hello world"; });
    //CROW_ROUTE(app, "/rpc")([](){ return "Hello world"; });
}

void CrowServer::Start(const int& port)
{
    //CROW_ROUTE(app, "/rpc")([](){ return "Hello world"; });
    app.port(port).multithreaded().run();
}
