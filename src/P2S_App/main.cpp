#include <iostream>
#include "../../dependencies/crow_all.h"

using namespace std;

int main()
{
    crow::SimpleApp app;

        CROW_ROUTE(app, "/rpc")([](){
            return "Hello world";
        });

        app.port(8080).multithreaded().run();
}

