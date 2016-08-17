#include "jsonrpcresponse.h"

using namespace P2S::Lib;
using namespace std;

using json = nlohmann::json;

JsonRpcResponse::JsonRpcResponse(string id)
{
    content["jsonrpc"] = "2.0";
    content["id"] = id;
}

string JsonRpcResponse::Serialize()
{
    assert(!validator.IsValid(content));
    return content.dump();
}

ErrorJsonRpcResponse::ErrorJsonRpcResponse(int code, string message, string id, string data) : JsonRpcResponse(id)
{
    content["error"]["code"] = code;
    content["error"]["message"] = message;
    content["error"]["data"] = data;
}

ValidJsonRpcResponse::ValidJsonRpcResponse(string result, string id) : JsonRpcResponse(id)
{
    content["result"] = result;
}
