#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "InetAddress.h"
using std::cin;
using std::cout;
using std::endl;


InetAddress::InetAddress(const string &ip_addr,unsigned short port){
    struct sockaddr_in ip;
    ip.sin_addr.s_addr = inet_pton(AF_INET,ip_addr.c_str(),&ip);
    if(ip.sin_addr.s_addr < 0){
        perror("InetAddress construct");
        return;
    }
    ip.sin_family = AF_INET;
    ip.sin_port = htons(port);
}

InetAddress::InetAddress(const struct sockaddr_in addr)
    :_ipaddr(addr)
{}

string InetAddress::getIpAddress(){
    if(_ipaddr.sin_addr.s_addr){
        return inet_ntoa(_ipaddr.sin_addr);
    }
    else if(!_addr.empty()){
        return _addr;
    }
    return " ";
}

unsigned short InetAddress::getPort(){
    if(_ipaddr.sin_port){
        return _ipaddr.sin_port;
    }
    else if(_port){
        return _port;
    }
    return 0;
}
