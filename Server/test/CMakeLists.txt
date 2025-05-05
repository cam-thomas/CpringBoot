cmake_minimum_required(VERSION 3.14)

# Set the project name
project(test_Server VERSION 1.0)

# GTest
enable_testing()

# Add the test executable
add_executable(
  test_Server
  test_Server.cpp
  ../HandlerManager.cpp
  ../Server.cpp
)

# Link GTest and other required libraries
target_link_libraries(
  test_Server
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_Server)