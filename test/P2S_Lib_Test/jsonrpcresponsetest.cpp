#include <gtest/gtest.h>
#include <jsonrpcrequest.h>

using namespace P2S::Lib;

TEST(RPCRequestTest, ParseCorrectJsonRPC) {
    JsonRpcRequest request;
    ASSERT_NO_THROW(request.Deserialize("{\"jsonrpc\": \"2.0\", \"method\":\"example\", \"params\": [42], \"id\": 2}"));
}

TEST(RPCRequestTest, ParseIncorrectJsonRPC) {
    JsonRpcRequest request;
    ASSERT_ANY_THROW(request.Deserialize("{\"jsonrpc\": \"2.0\".... \"method\":\"example\", \"id\": 2}"));
}
