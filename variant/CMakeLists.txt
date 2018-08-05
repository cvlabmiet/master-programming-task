cmake_minimum_required(VERSION 3.9)
project(variant VERSION 0.1.0 LANGUAGES CXX DESCRIPTION "Implements variant classes")

include(CTest)
include(../ParseAndAddCatchTests.cmake)
set(CMAKE_CXX_STANDARD 17)

add_library(variant INTERFACE)
target_include_directories(variant INTERFACE include)

find_package(Boost REQUIRED)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_variant ${TESTS})
target_link_libraries(tests_variant variant Catch1x Boost::boost)
ParseAndAddCatchTests(tests_variant)
