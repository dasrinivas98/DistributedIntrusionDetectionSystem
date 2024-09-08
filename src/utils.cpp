// utils.cpp
#include "utils.h"
#include <iostream>
#include <fstream>

void logMessage(const std::string& message) {
    // Define the log file path
    static const std::string logFilePath = "application.log";

    // Open the file in append mode
    std::ofstream logFile(logFilePath, std::ios_base::app);
    
    // Check if the file was opened successfully
    if (logFile) {
        logFile << "[LOG] " << message << std::endl;
    } else {
        // If the file couldn't be opened, print an error to the console
        std::cerr << "Error: Could not open log file!" << std::endl;
    }
}
