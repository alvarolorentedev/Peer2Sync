#include "rpcrequest.h"

using namespace P2S::Lib;
using namespace std;

using json = nlohmann::json;


void RPCRequest::Parse(const string &rawContent)
{
    auto parsed = json::parse(rawContent);
    if(!Validate(parsed))
        throw RequestParseException("json is not valid JSON-RPC 2.0");
    content = parsed;
}

bool RPCRequest::Validate(nlohmann::json object)
{
    for (auto const &rule : rules)
        if(!rule(object))
            return false;
    return true;
}
