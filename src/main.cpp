#include "detector.h"
#include "network.h"
#include "simulator.h"
#include "utils.h"
#include <iostream>
#include <thread>

int main() {
    logMessage("Program Started"); 
    // Initialize network
    Network net;
    net.start();

    // Start traffic simulation in a separate thread
    std::thread trafficThread(simulateTraffic, std::ref(net));

    // Initialize intrusion detector
    IntrusionDetector detector;

    // Process incoming data from the network and analyze it
    while (true) {
        std::string data = net.receiveData();
        if (detector.detectIntrusion(data)) {
            std::cout << "Intrusion detected! Data: " << data << std::endl;
        }
    }

    // Join the traffic thread to ensure it runs alongside the main thread
    trafficThread.join();

    return 0;
}
