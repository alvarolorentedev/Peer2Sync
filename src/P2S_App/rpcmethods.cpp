#include "rpcmethods.h"
#include <jsonrpcresponse.h>
#include <jsonrpcrequest.h>
#include "datastoreput.h"
#include "datastoreget.h"
#include "datastoremeta.h"

using namespace P2S::App;
using namespace P2S::Lib;
using namespace std;

RpcMethods::RpcMethods(const IServerPtr& server, const IDataStorePtr &dstore) : paths(
    {
        { "datastorePut" , make_shared<DataStorePut>(dstore) },
        { "datastoreGet" , make_shared<DataStoreGet>(dstore) },
        { "datastoreMeta" , make_shared<DataStoreMeta>(dstore) }
    })
{
    server->Subscribe("/rpc", HTTPMethod::POST, [&](const string& req){

        JsonRpcRequest request;
        IResponsePtr response;
        try{
            request.Deserialize(req);
            if(this->paths.find(request.GetMethod()) == this->paths.end())
                throw("Method does not exist");
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
