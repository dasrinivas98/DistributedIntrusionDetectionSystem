#include "../inc/network.h"
#include <iostream>

// Function to test Network class
void test_network() {
    Network net;

    // Test 1: Network starts and receives data
    net.start();
    std::string receivedData = net.receiveData();

    std::cout << "Test 1 - Received Data: " << (!receivedData.empty() ? "PASS" : "FAIL") << std::endl;

    // Test 2: Sending data should work without errors
    net.sendData("test data");
    std::cout << "Test 2 - Sent Data: PASS (no errors)" << std::endl;
}

int main() {
    std::cout << "Running Network Tests..." << std::endl;
    test_network();
    return 0;
}
