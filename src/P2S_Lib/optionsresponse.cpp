#include "optionsresponse.h"

using namespace P2S::Lib;
using namespace std;

string OptionsRPCResponse::Serialize()
{
    return "Allow: POST,OPTIONS";
}
