#include "jsonrpcresponse.h"

using namespace P2S::Lib;
using namespace std;

using json = nlohmann::json;

string JsonRpcResponse::Serialize()
{
    assert(!validator.IsValid(content));
    return content.dump();
}
