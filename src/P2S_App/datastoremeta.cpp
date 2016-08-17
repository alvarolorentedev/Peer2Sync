#include "datastoremeta.h"
#include <jsonrpcresponse.h>

using namespace P2S::App;
using namespace P2S::Lib;
using namespace std;

DataStoreMeta::DataStoreMeta(const IDataStorePtr& dstore)
{
    datastore = dstore;
}

string DataStoreMeta::Execute(const nlohmann::json &params)
{
    return nlohmann::json(datastore->Meta(params["collection"])).dump();
}
