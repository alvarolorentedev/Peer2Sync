#include "datastoreput.h"


using namespace P2S::App;
using namespace P2S::Lib;
using namespace std;

DataStorePut::DataStorePut(const IDataStorePtr& dstore)
{
    datastore = dstore;
}

IResponsePtr DataStorePut::Execute(const nlohmann::json &params)
{
    throw("Not Implemented Exception");
}
