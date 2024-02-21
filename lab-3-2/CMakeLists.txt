cmake_minimum_required(VERSION 3.00)
project(lab-3-2)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab-3-2 main.cpp array.cpp point.cpp figures.cpp array.hpp point.hpp figures.hpp)

enable_testing()
add_executable(tests  tests.cpp main.cpp array.cpp point.cpp figures.cpp array.hpp point.hpp figures.hpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)

