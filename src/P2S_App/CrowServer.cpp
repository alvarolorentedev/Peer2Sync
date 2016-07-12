#include "CrowServer.h"

using namespace P2S::App;

void CrowServer::Subscribe(const std::string& path, const HTTPMethod& method, const std::function<void()>& func)
{
    app.route_dynamic(std::string(path)).methods(methods[method])
            ([&](const crow::request& req){
                auto params = crow::json::load(req.body);
                func();
                return crow::response{params};
            });
}

void CrowServer::Start(const int& port)
{
    app.port(port).multithreaded().run();
}
