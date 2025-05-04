cmake_minimum_required(VERSION 3.14)

# Set the project name
project(Server VERSION 1.0)

# Add all source files in the current directory to the executable
file(GLOB SOURCES "*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# Create the executable from the source files
add_library(${PROJECT_NAME} ${SOURCES})

add_subdirectory(test)

