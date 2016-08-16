#include "CrowServer.h"
#include "IServer.h"
#include "rpcmethods.h"
#include <jsonrpcresponse.h>
#include <redisdatastore.h>

using namespace std;
using namespace P2S::App;
using namespace P2S::Lib;

/**
 * @name    Main
 * @brief   Entrypoit of application
 */
int main(/*int, char *argv[]*/)
{
    auto server = make_shared<CrowServer>();
    auto dataStore = make_shared<RedisDataStore>();
    dataStore->Connect(getenv("REDIS_IP"), atoi(getenv("REDIS_PORT")));
    RpcMethods methods(server, dataStore);
    server->Start(atoi(getenv("PORT")));
}

