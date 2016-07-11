#ifndef SERVER_H
#define SERVER_H

#include "IServer.h"

namespace P2S {
namespace App {

class CrowServer : public IServer
{
public:
    CrowServer() = default;
    virtual void start(int port);
};

}
}

#endif // SERVER_H
