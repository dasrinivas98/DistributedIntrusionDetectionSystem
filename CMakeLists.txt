cmake_minimum_required(VERSION 3.10)
project(DistributedIntrusionDetectionSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for headers
include_directories(${CMAKE_SOURCE_DIR}/inc)

# Define source files for the main project
set(SOURCES
    src/main.cpp
    src/detector.cpp
    src/network.cpp
    src/utils.cpp
    src/simulator.cpp
)

# Add the main executable
add_executable(DistributedIntrusionDetectionSystem ${SOURCES})

# Add the tests directory
add_subdirectory(tests)
