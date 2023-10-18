#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include "Socket.h"
using std::cin;
using std::cout;
using std::endl;


Socket::Socket(){
    _socketFd = socket(AF_INET,SOCK_STREAM,0);
    if(_socketFd == -1){
        perror("Socket");
        return;
    }
}

Socket::Socket(int socketfd)
    :_socketFd(socketfd)
{}

Socket::~Socket(){}

int Socket::getSocketFd(){
    return _socketFd;
}
