#include "CrowServer.h"
#include "IServer.h"
#include "rpcmethods.h"
#include <jsonrpcresponse.h>

using namespace std;
using namespace P2S::App;
using namespace P2S::Lib;

/**
 * @name    Main
 * @brief   Entrypoit of application
 */
int main(/*int argc, char *argv[]*/)
{
    auto server = std::make_shared<CrowServer>();
    RpcMethods methods(server);
    server->Start(8080);
}

