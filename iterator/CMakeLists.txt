cmake_minimum_required(VERSION 3.9)
project(iterator VERSION 0.1.0 LANGUAGES CXX DESCRIPTION "Implements image iterator")

include(CTest)
include(../ParseAndAddCatchTests.cmake)
set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)

add_library(iterator INTERFACE)
target_include_directories(iterator INTERFACE include)
target_link_libraries(iterator INTERFACE Boost::boost)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_iterator ${TESTS})
target_link_libraries(tests_iterator iterator Catch1x)
ParseAndAddCatchTests(tests_iterator)
