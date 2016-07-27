#include "rpcmethods.h"
#include <jsonrpcresponse.h>
#include <jsonrpcrequest.h>

using namespace P2S::App;
using namespace P2S::Lib;
using namespace std;

RpcMethods::RpcMethods(const IServerPtr& server)
{
    server->Subscribe("/rpc", HTTPMethod::POST, [&](const string& req){
        JsonRpcRequest request;
        request.Deserialize(req);
        this->paths[request.GetMethod()](request.GetParams());
        return make_shared<ValidJsonRpcResponse>("TODO",10);
    });
}

