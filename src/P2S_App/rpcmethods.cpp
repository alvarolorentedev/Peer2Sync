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
        IResponsePtr response;
        try{
            response = this->paths[request.GetMethod()](request.GetParams());
        }
        catch(...)
        {
            //TODO: generate valid error response
            response = make_shared<ErrorJsonRpcResponse>(0,"Exception has been throw",0);
        }
        return response;
    });
}

