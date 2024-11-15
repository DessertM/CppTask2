cmake_minimum_required(VERSION 3.14)

project(Task2)

add_library(Task2Lib SHARED Task2/Logarithm.cpp Task2/GCD.cpp Task2/Taylor.cpp)

add_executable(Task2Tests Task2.Tests/Logarithm.Tests.cpp Task2.Tests/GCD.Tests.cpp Task2.Tests/Taylor.Tests.cpp)

target_link_libraries(Task2Tests Task2Lib gtest_main gtest pthread)