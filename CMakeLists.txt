cmake_minimum_required(VERSION 3.14)

project(Task2)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(Task2Lib STATIC Task2/Logarithm.cpp Task2/GCD.cpp Task2/Taylor.cpp)

add_executable(Task2Tests Task2.Tests/Logarithm.Tests.cpp Task2.Tests/GCD.Tests.cpp Task2.Tests/Taylor.Tests.cpp)

target_link_libraries(Task2Tests Task2Lib)
target_link_libraries(Task2Tests GTest::gtest_main)
