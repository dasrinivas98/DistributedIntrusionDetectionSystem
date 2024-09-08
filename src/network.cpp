#include "network.h"
#include <iostream>
#include "utils.h"

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "Ws2_32.lib")
#endif

void Network::start() {
#ifdef _WIN32
    // Initialize Winsock
    logMessage("Initializing Winsock");
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock.\n";
        return;
    }

    // Create socket
    logMessage("Creating Socket");
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Socket creation failed.\n";
        WSACleanup();
        return;
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(8080);

    if (bind(sock, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        std::cerr << "Bind failed.\n";
        closesocket(sock);
        WSACleanup();
        return;
    }

    if (listen(sock, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed.\n";
        closesocket(sock);
        WSACleanup();
        return;
    }
    logMessage("Network started");
    std::cout << "Network started...\n";
#else
    // Linux socket setup (not implemented here)
#endif
}

std::string Network::receiveData() {
logMessage("network::receiveData() called");    
#ifdef _WIN32
    char buffer[512];
    sockaddr_in client;
    int clientSize = sizeof(client);
    SOCKET clientSocket = accept(sock, (sockaddr*)&client, &clientSize);

    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Accept failed.\n";
        return "";
    }

    int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0'; // Null-terminate the received data
        closesocket(clientSocket);
        return std::string(buffer);
    }
    closesocket(clientSocket);
    return "";
#else
    // Linux socket receive (not implemented here)
#endif
}

void Network::sendData(const std::string& data) {
    logMessage("network::sendData() called");    
#ifdef _WIN32
    sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = inet_addr("127.0.0.1");
    client.sin_port = htons(8080);

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed.\n";
        return;
    }

    if (connect(clientSocket, (sockaddr*)&client, sizeof(client)) == SOCKET_ERROR) {
        std::cerr << "Connection failed.\n";
        closesocket(clientSocket);
        return;
    }

    send(clientSocket, data.c_str(), data.length(), 0);
    closesocket(clientSocket);
#else
    // Linux implementation (not provided)
#endif
}
