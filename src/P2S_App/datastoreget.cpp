#include "datastoreget.h"
#include <jsonrpcresponse.h>

using namespace P2S::App;
using namespace P2S::Lib;
using namespace std;

DataStoreGet::DataStoreGet(const IDataStorePtr& dstore)
{
    datastore = dstore;
}

IResponsePtr DataStoreGet::Execute(const nlohmann::json &params)
{
    std::vector<nlohmann::json> result;
    auto all = params["all"].get<bool>();
    if(all)
        result = datastore->Get(params["collection"]);
    else{
        auto ids = params["ids"];
        vector<string> idsVector;
        for (auto& id : ids)
            idsVector.push_back(id.get<string>());
        result = datastore->Get(params["collection"], ids);
    }
    return make_shared<ValidJsonRpcResponse>(nlohmann::json(result).dump(),0);
}
