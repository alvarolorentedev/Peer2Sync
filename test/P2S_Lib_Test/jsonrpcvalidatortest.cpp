#include <gtest/gtest.h>
#include <jsonrpcrequest.h>
#include "../../dependencies/json.hpp"

using namespace P2S::Lib;
using json = nlohmann::json;

TEST(JSonRPC2ValidatorTest, CorrectJsonRPC) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"jsonrpc\": \"2.0\", \"method\":\"example\", \"params\": [42], \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(true, validator.IsValid(parsed));
}

TEST(JSonRPC2ValidatorTest, InvalidJsonNoRPCVersion) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"method\":\"example\", \"params\": [42], \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(false, validator.IsValid(parsed));
}

TEST(JSonRPC2ValidatorTest, InvalidJsonRPCVersion) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"jsonrpc\": \"1.0\", \"method\":\"example\", \"params\": [42], \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(false, validator.IsValid(parsed));
}

TEST(JSonRPC2ValidatorTest, InvalidJsonRPCMethod) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"jsonrpc\": \"2.0\", \"params\": [42], \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(false, validator.IsValid(parsed));
}
