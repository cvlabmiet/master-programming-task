cmake_minimum_required(VERSION 3.9)
project(json VERSION 0.1.0 LANGUAGES CXX DESCRIPTION "Implements serialization procedure")

include(CTest)
include(../ParseAndAddCatchTests.cmake)
set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS system REQUIRED)

add_library(parser INTERFACE)
target_include_directories(parser INTERFACE include Boost::boost)
target_link_libraries(parser INTERFACE Boost::system)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_parser ${TESTS})
target_link_libraries(tests_parser parser Catch1x)
ParseAndAddCatchTests(tests_parser)
