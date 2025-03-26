cmake_minimum_required(VERSION 3.0.0)

# Set the project name
project(CpringBoot)

# Enable C++17 standard
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

#Add include directories
include_directories(Server)

# Add subdirectories
add_subdirectory(Server)

# Add executable
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} Server)