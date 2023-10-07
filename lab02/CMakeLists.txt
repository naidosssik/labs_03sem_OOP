cmake_minimum_required(VERSION 3.12)
project(Eleven_Class)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Eleven_Class main.cpp eleven.cpp tests.cpp)
target_link_libraries(MyElevenProject ${GTEST_LIBRARIES})
