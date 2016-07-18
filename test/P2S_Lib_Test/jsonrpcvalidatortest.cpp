#include <gtest/gtest.h>
#include <jsonrpcrequest.h>
#include "../../dependencies/json.hpp"

using namespace P2S::Lib;
using json = nlohmann::json;

TEST(JSonRPCRequestValidatorTest, CorrectJsonRPC) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"jsonrpc\": \"2.0\", \"method\":\"example\", \"params\": [42], \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(true, validator.IsValid(parsed));
}

TEST(JSonRPCRequestValidatorTest, InvalidJsonNoRPCVersion) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"method\":\"example\", \"params\": [42], \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(false, validator.IsValid(parsed));
}

TEST(JSonRPCRequestValidatorTest, InvalidJsonRPCVersion) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"jsonrpc\": \"1.0\", \"method\":\"example\", \"params\": [42], \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(false, validator.IsValid(parsed));
}

TEST(JSonRPCRequestValidatorTest, InvalidJsonRPCMethod) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"jsonrpc\": \"2.0\", \"params\": [42], \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(false, validator.IsValid(parsed));
}

TEST(JSonRPCResponseValidatorTest, CorrectJsonRPCResult) {
    JSonRPCResponseValidator validator;
    auto jsonText = "{\"jsonrpc\": \"2.0\", \"result\":\"example\", \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(true, validator.IsValid(parsed));
}

TEST(JSonRPCResponseValidatorTest, CorrectJsonRPCError) {
    JSonRPCResponseValidator validator;
    auto jsonText = "{\"jsonrpc\": \"2.0\", \"error\":{}, \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(true, validator.IsValid(parsed));
}

TEST(JSonRPCResponseValidatorTest, InvalidJsonNoRPCVersion) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"result\":\"example\", \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(false, validator.IsValid(parsed));
}

TEST(JSonRPCResponseValidatorTest, InvalidJsonRPCVersion) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"jsonrpc\": \"1.0\", \"result\":\"example\", \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(false, validator.IsValid(parsed));
}

TEST(JSonRPCResponseValidatorTest, InvalidJsonRPCResultError) {
    JSonRPCRequestValidator validator;
    auto jsonText = "{\"jsonrpc\": \"2.0\", \"result\":\"example\", \"error\":{}, \"id\": 2}";
    auto parsed = json::parse(jsonText);
    EXPECT_EQ(false, validator.IsValid(parsed));
}
