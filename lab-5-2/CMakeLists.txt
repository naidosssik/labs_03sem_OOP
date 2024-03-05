# add_executable(lab5 main.cpp allocator/allocator.hpp iterator/iterator_const.hpp iterator/iterator.hpp list/list.hpp)

    # target_include_directories(lab5 PRIVATE list iterators allocator)

    # cmake_minimum_required(VERSION 3.10)
    # project(lab05)

    # set(CMAKE_CXX_STANDARD 20)
    # set(CMAKE_CXX_STANDARD_REQUIRED ON)

    # set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
    # set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

    # include_directories(${INCLUDE_DIR})

    # file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false ${TEST_DIR}/*.cpp)

    # # add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})
    # add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)
    # add_executable(${CMAKE_PROJECT_NAME}_test ${TEST_SOURCES})

    # # target_link_libraries(${CMAKE_PROJECT_NAME}_exe PRIVATE ${CMAKE_PROJECT_NAME}_lib)
    # target_include_directories(${CMAKE_PROJECT_NAME}_test PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    # target_link_libraries(${CMAKE_PROJECT_NAME}_test PRIVATE gtest gtest_main)

    # add_test(NAME BASIC COMMAND tests01)



cmake_minimum_required(VERSION 3.00)
project(lab5)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab5 main.cpp allocator.hpp iterator_const.hpp iterator.hpp list.hpp)

enable_testing()
add_executable(tests tests.cpp main.cpp allocator.hpp iterator_const.hpp iterator.hpp list.hpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)

