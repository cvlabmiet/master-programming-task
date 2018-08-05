cmake_minimum_required(VERSION 3.9)
project(iomanip VERSION 0.1.0 LANGUAGES CXX DESCRIPTION "Implements some iomanips")

include(CTest)
include(../ParseAndAddCatchTests.cmake)
set(CMAKE_CXX_STANDARD 17)

add_library(iomanip INTERFACE)
target_include_directories(iomanip INTERFACE include)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_iomanip ${TESTS})
target_link_libraries(tests_iomanip iomanip Catch1x)
ParseAndAddCatchTests(tests_iomanip)
