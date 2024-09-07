#include "detector.h"
#include "network.h"
#include <iostream>

int main() {
    // Initialize network (e.g., start listening on a socket)
    Network net;
    net.start();

    // Initialize intrusion detector
    IntrusionDetector detector;

    // Process incoming data from the network and analyze it
    while (true) {
        std::string data = net.receiveData();
        if (detector.detectIntrusion(data)) {
            std::cout << "Intrusion detected! Data: " << data << std::endl;
        }
    }

    return 0;
}
