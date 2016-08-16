#include "datastoremeta.h"
#include <jsonrpcresponse.h>

using namespace P2S::App;
using namespace P2S::Lib;
using namespace std;

DataStoreMeta::DataStoreMeta(const IDataStorePtr& dstore)
{
    datastore = dstore;
}

IResponsePtr DataStoreMeta::Execute(const nlohmann::json &params)
{
    std::vector<nlohmann::json> result = datastore->Meta(params["collection"]);
    return make_shared<ValidJsonRpcResponse>(nlohmann::json(result).dump(),0);
}
