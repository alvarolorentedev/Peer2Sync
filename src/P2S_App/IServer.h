#ifndef ISERVER_H
#define ISERVER_H

namespace P2S {
namespace App {

    class IServer
    {
    public:
        virtual void start(int port) = 0;
        virtual ~IServer() = default;
    };
}
}

#endif // ISERVER_H

