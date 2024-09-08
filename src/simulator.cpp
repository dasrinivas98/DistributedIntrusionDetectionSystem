#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include "network.h"
#include "detector.h"
#include "utils.h"

void simulateTraffic(Network& net) {
    logMessage("simulating network traffic");  
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 1);

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        std::string simulatedData = (distribution(generator) == 0) ? "normal data" : "malicious data";
        std::cout << "Simulating traffic: " << simulatedData << std::endl;
        net.sendData(simulatedData);
    }
}
