#ifndef __SOCKET__
#define __SOCKET__

class Socket
{
public:
    Socket();
    Socket(int socketfd);
    ~Socket();
    int getSocketFd();
private:
    int _socketFd;
};
#endif


