#include "detector.h"
#include <iostream>

// Function to test IntrusionDetector class
void test_detector() {
    IntrusionDetector detector;

    // Test 1: Malicious data should trigger intrusion detection
    std::string maliciousData = "malicious data";
    bool intrusionDetected = detector.detectIntrusion(maliciousData);
    std::cout << "Test 1 - Malicious Data: " << (intrusionDetected ? "PASS" : "FAIL") << std::endl;

    // Test 2: Safe data should not trigger intrusion detection
    std::string safeData = "normal data";
    intrusionDetected = detector.detectIntrusion(safeData);
    std::cout << "Test 2 - Safe Data: " << (!intrusionDetected ? "PASS" : "FAIL") << std::endl;
}

int main() {
    std::cout << "Running Intrusion Detector Tests..." << std::endl;
    test_detector();
    return 0;
}
