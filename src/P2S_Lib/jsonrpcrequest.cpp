#include "jsonrpcrequest.h"

using namespace P2S::Lib;
using namespace std;

using json = nlohmann::json;

void JsonRpcRequest::Deserialize(const string &rawContent)
{
    auto parsed = json::parse(rawContent);
    if(!validator.IsValid(parsed))
        throw RequestParseException("json is not valid JSON-RPC 2.0");
    content = parsed;
}
