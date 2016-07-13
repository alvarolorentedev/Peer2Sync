#include "rpcrequest.h"

using namespace P2S::Lib;
using namespace std;

using json = nlohmann::json;


void RPCRequest::Parse(const string &rawContent)
{
    content = json::parse(rawContent);
}
