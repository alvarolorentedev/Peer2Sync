#include "rpcmethods.h"
#include <jsonrpcresponse.h>
#include <jsonrpcrequest.h>
#include "datastoreput.h"

using namespace P2S::App;
using namespace P2S::Lib;
using namespace std;

RpcMethods::RpcMethods(const IServerPtr& server, const IDataStorePtr &dstore) : paths(
    {
        { "datastorePut" , make_shared<DataStorePut>(dstore) }
    })
{
    server->Subscribe("/rpc", HTTPMethod::POST, [&](const string& req){

        JsonRpcRequest request;
        IResponsePtr response;
        try{
            request.Deserialize(req);
            response = this->paths[request.GetMethod()]->Execute(request.GetParams());
        }
        catch(...)
        {
            //TODO: generate valid error response
            response = make_shared<ErrorJsonRpcResponse>(0,"Exception has been throw",0);
        }
        return response;
    });
}
