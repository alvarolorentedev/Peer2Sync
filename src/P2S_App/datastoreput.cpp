#include "datastoreput.h"
#include <jsonrpcresponse.h>

using namespace P2S::App;
using namespace P2S::Lib;
using namespace std;

DataStorePut::DataStorePut(const IDataStorePtr& dstore)
{
    datastore = dstore;
}

string DataStorePut::Execute(const nlohmann::json &params)
{
    auto allChanges = params["changes"];
    vector<nlohmann::json> changes;
    for (auto& change : allChanges)
        changes.push_back(change);
    datastore->Put(params["collection"], changes);
    return "";
}
