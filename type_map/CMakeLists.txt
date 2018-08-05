cmake_minimum_required(VERSION 3.9)
project(type_map VERSION 0.1.0 LANGUAGES CXX DESCRIPTION "Implements map of types")

include(CTest)
include(../ParseAndAddCatchTests.cmake)
set(CMAKE_CXX_STANDARD 17)

add_library(type_map INTERFACE)
target_include_directories(type_map INTERFACE include)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_type_map ${TESTS})
target_link_libraries(tests_type_map type_map Catch1x)
ParseAndAddCatchTests(tests_type_map)
