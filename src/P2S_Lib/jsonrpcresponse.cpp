#include "jsonrpcresponse.h"

using namespace P2S::Lib;
using namespace std;

using json = nlohmann::json;

JsonRpcResponse::JsonRpcResponse(uint32_t id)
{
    content["jsonrpc"] = "2.0";
    content["id"] = id;
}

string JsonRpcResponse::Serialize()
{
    assert(!validator.IsValid(content));
    return content.dump();
}

ErrorJsonRpcResponse::ErrorJsonRpcResponse(int code, string message, uint16_t id, string data) : JsonRpcResponse(id)
{
    content["error"]["code"] = code;
    content["error"]["message"] = message;
    content["error"]["data"] = data;
}

ValidJsonRpcResponse::ValidJsonRpcResponse(string result, uint16_t id) : JsonRpcResponse(id)
{
    content["result"] = result;
}
