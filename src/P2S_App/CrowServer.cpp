#include "CrowServer.h"

using namespace P2S::App;
using namespace P2S::Lib;

void CrowServer::Subscribe(const std::string& path, const HTTPMethod& method, const std::function<IResponsePtr(std::string)>& func)
{
    app.route_dynamic(std::string(path)).methods(methods[method])
            ([&](const crow::request& req){
                return func(req.body)->Serialize();
            });
}

void CrowServer::Start(const int& port)
{
    app.port(port).multithreaded().run();
}
