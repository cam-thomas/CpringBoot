cmake_minimum_required(VERSION 3.14)

# Set the project name
project(test_Server VERSION 1.0)

#GTest

# Add all source files in the current directory to the executable
file(GLOB SOURCES "*.cpp")


enable_testing()

add_executable(
  test_Server
  test_Server.cpp
)
target_link_libraries(
  test_Server
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_Server)