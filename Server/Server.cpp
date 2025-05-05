//Project includes
#include <Server.h>

// Standard includes
#include <iostream>
#include <thread>

// Network includes
#include <cstring>
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
    int address = 1;
    // Set the socket to allow reuse of the address
    setsockopt(socfd, SOL_SOCKET, SO_REUSEADDR, &address, sizeof(address));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(portNum);

    if (bind(socfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Error on binding");
        close(socfd);
        exit(1);
    }
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

void Server::Serve() {

    if (listen(socfd, MAX_CONNECTIONS) == -1) {
		std::cout << "Error listening to socket: " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}
    listen(socfd, MAX_CONNECTIONS);
    while (true) {

		int connectionfd = accept(socfd, 0, 0);
		if (connectionfd == -1) {
			perror("Error accepting connection");
			continue;
		}

		// std::thread connection_thread(&Server::HandleConnection, this, connectionfd);
		// connection_thread.detach();
	}
}