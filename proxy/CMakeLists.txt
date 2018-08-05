cmake_minimum_required(VERSION 3.9)
project(proxy VERSION 0.1.0 LANGUAGES CXX DESCRIPTION "Implements proxy object with guard")

include(CTest)
include(../ParseAndAddCatchTests.cmake)
set(CMAKE_CXX_STANDARD 17)

add_library(proxy INTERFACE)
target_include_directories(proxy INTERFACE include)
target_link_libraries(proxy INTERFACE pthread)

find_package(Boost REQUIRED)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_proxy ${TESTS})
target_link_libraries(tests_proxy proxy Catch1x Boost::boost)
ParseAndAddCatchTests(tests_proxy)
