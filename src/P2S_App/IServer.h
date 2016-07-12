#ifndef ISERVER_H
#define ISERVER_H
#include <functional>
#include <iostream>
namespace P2S {
namespace App {

class IServer
{
public:
    virtual void Subscribe(const std::string& path, std::function<void()>& function) = 0;
    virtual void Start(const int& port) = 0;
    virtual ~IServer() = default;
};

}
}

#endif // ISERVER_H

