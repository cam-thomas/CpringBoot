#pragma once

#include <functional>
#include <map>
#include "Types.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

class Server {
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
};