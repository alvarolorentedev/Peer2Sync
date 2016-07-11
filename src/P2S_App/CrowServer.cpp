#include "CrowServer.h"
#include "../../dependencies/crow_all.h"

using namespace P2S::App;

void CrowServer::start(int port)
{
    crow::SimpleApp app;
    CROW_ROUTE(app, "/rpc")([](){ return "Hello world"; });
    app.port(port).multithreaded().run();
}

