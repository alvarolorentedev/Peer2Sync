#include <gtest/gtest.h>
#include <optionsresponse.h>

using namespace P2S::Lib;

TEST(RPCOptionsResponseTest, RPCOptionsTest) {
    OptionsRPCResponse response;
    EXPECT_EQ("Allow: POST,OPTIONS", response.Serialize());
}
