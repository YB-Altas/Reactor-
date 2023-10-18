#ifndef __INET_ADDRESS__
#define __INET_ADDRESS__
#include <iostream>
#include <netinet/in.h>
using std::string;

class InetAddress
{
public:
    InetAddress(const string &ip_addr,unsigned short port);
    InetAddress(const struct sockaddr_in ipaddr);
    ~InetAddress();
    string getIpAddress();
    unsigned short getPort();
private:
    int bind();
    int listen();
private:
    struct sockaddr_in _ipaddr;
    string _addr;
    unsigned short _port;
};
#endif
