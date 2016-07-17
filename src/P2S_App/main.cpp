#include "CrowServer.h"
#include "IServer.h"
#include <jsonrpcresponse.h>

using namespace std;
using namespace P2S::App;
using namespace P2S::Lib;

int main(/*int argc, char *argv[]*/)
{
    std::unique_ptr<IServer> server = std::make_unique<CrowServer>();
    server->Subscribe("/rpc", HTTPMethod::POST, [&](const string& req){
        return make_shared<ValidJsonRpcResponse>("TODO",10);
    });
    server->Start(8080);
}

