#include <gtest/gtest.h>
#include <jsonrpcresponse.h>

using namespace P2S::Lib;

TEST(RPCResponseTest, ValidJsonRpcResponseTest) {
    ValidJsonRpcResponse response("it works", "10");
    EXPECT_EQ("{\"id\":\"10\",\"jsonrpc\":\"2.0\",\"result\":\"it works\"}", response.Serialize());
}

TEST(RPCResponseTest, ErrorJsonRpcResponseTest) {
    ErrorJsonRpcResponse response(-32700,"Parse Error", "10");
    EXPECT_EQ("{\"error\":{\"code\":-32700,\"data\":\"\",\"message\":\"Parse Error\"},\"id\":\"10\",\"jsonrpc\":\"2.0\"}", response.Serialize());
}
