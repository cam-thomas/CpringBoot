#include <Server.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

namespace {
    const int MAX_CONNECTIONS = 5;
    const int MAX_BUFFER_SIZE = 4096;
}

Server::Server(int portNum) : portNum(portNum), msgsock(-1), socfd(-1) {
    buf = new char[MAX_BUFFER_SIZE];
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(portNum);
    
    socfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socfd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    
    if (bind(socfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error on binding");
        close(socfd);
        exit(1);
    }
    
    listen(socfd, MAX_CONNECTIONS);
}
Server::~Server() {
    if (msgsock != -1) {
        close(msgsock);
    }
    if (socfd != -1) {
        close(socfd);
    }
    delete[] buf;
}