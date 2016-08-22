#include "CrowServer.h"

using namespace P2S::App;
using namespace P2S::Lib;

void CrowServer::Subscribe(const std::string& path, const HTTPMethod& method, const std::function<IResponsePtr(std::string)>& func)
{
    app.route_dynamic(std::string(path)).methods(methods[method])
            ([&, func](const crow::request& req){
                crow::response response;
                response.add_header("Access-Control-Allow-Origin", "*");
                response.add_header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
                response.body = func(req.body)->Serialize();
                return response;
            });
}

void CrowServer::Start(const int& port)
{
    app.port(port).multithreaded().run();
}
