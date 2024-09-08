#include "detector.h"

bool IntrusionDetector::detectIntrusion(const std::string& data) {
    // Example detection logic (to be expanded with real anomaly detection)
    return data.find("malicious") != std::string::npos;
}
