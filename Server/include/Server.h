#pragma once

#include <functional>
#include <map>
#include <string>
#include "Types.h"
#include "Handler.h"
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
    //std::map<int, std::function<void(...)>> handlers;


    class HandlerManager {
    public:
        HandlerManager() = default;
        ~HandlerManager() = default;

       void RegisterHandler(std::string path, Handler handler);
       Handler& GetHandler(std::string path);
    private:
        std::map<std::string, Handler> handlers;
    };
    HandlerManager handlerManager;
};