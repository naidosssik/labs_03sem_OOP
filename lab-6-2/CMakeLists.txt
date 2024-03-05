cmake_minimum_required(VERSION 3.00)
project(lab6)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab6 main.cpp include/dragon.hpp include/factory.hpp include/npc.hpp include/observer.hpp include/elf.hpp include/druid.hpp include/visitor.hpp src/dragon.cpp src/factory.cpp src/npc.cpp src/observer.cpp src/elf.cpp src/druid.cpp src/visitor.cpp)


enable_testing()
add_executable(tests tests.cpp main.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)

