#include "rpcmethods.h"
#include <jsonrpcresponse.h>
#include <jsonrpcrequest.h>
#include <optionsresponse.h>
#include "datastoreput.h"
#include "datastoreget.h"
#include "datastoremeta.h"

using namespace P2S::App;
using namespace P2S::Lib;
using namespace std;

class NoMethodException : public std::runtime_error
{
public:
  NoMethodException(const std::string & err) : std::runtime_error(err) {}
};

RpcMethods::RpcMethods(const IServerPtr& server, const IDataStorePtr &dstore) : paths(
    {
        { "datastorePut" , make_shared<DataStorePut>(dstore) },
        { "datastoreGet" , make_shared<DataStoreGet>(dstore) },
        { "datastoreMeta" , make_shared<DataStoreMeta>(dstore) }
    })
{

    server->Subscribe("/rpc", [&](const string& req, HTTPMethod method){
        if(method == HTTPMethod::POST)
            return Post(req);
        else if (method == HTTPMethod::OPTIONS)
            return Options();
        else
            throw NoMethodException("this method does not exists");
    });
}

IResponsePtr RpcMethods::Post(const std::string& req)
{
        JsonRpcRequest request;
        IResponsePtr response;
        string id = "";
        try{
            request.Deserialize(req);
            id = request.GetId();
            auto method = request.GetMethod();
            if(this->paths.find(method) == this->paths.end())
                response = make_shared<ErrorJsonRpcResponse>(-32601,"Method does not exist",id);
            else
                response = make_shared<ValidJsonRpcResponse>(this->paths[method]->Execute(request.GetParams()),id);
        }
        catch(const DataStoreException& ex)
        {
            response = make_shared<ErrorJsonRpcResponse>(-32603,ex.what(), id);
        }
        catch(const std::exception& ex)
        {
            response = make_shared<ErrorJsonRpcResponse>(-32600,ex.what(),id);
        }
        return response;
}

IResponsePtr RpcMethods::Options()
{
        IResponsePtr response;
        response = make_shared<OptionsRPCResponse>();
        return response;
}
