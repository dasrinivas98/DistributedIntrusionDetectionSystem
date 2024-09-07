#ifndef NETWORK_H
#define NETWORK_H

#include <string>

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "Ws2_32.lib")
#endif

class Network {
public:
    void start();
    std::string receiveData();
    void sendData(const std::string& data);
private:
#ifdef _WIN32
    WSADATA wsaData;
    SOCKET sock;
#endif
};

#endif
