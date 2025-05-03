#pragma once

#include <functional>
#include <map>
#include "Types.h"

class Server {
    Server(int portNum = 8080);
    ~Server();
    
protected:
    handleConnection
private:
    int portNum;
    int msgsock;
    int socfd;
    struct sockaddr_in addr;
    char *buf;
};