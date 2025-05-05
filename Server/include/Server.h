#pragma once

#include <functional>
#include <map>
#include <string>
#include "Types.h"
#include "HandlerManager.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

class Server {
public:
    Server(int portNum = 8080);
    ~Server();
    
protected:
    void HandleConnection(int connectionfd);
private:
    void Serve();

    int portNum;
    int msgsock;
    int socfd;
    struct sockaddr_in addr;
    char *buf;

    HandlerManager handlerManager;
};