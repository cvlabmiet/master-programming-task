cmake_minimum_required(VERSION 3.12)
project(cxx-tasks VERSION 0.2.1 LANGUAGES CXX DESCRIPTION "Home tasks for C++ training")

set(CMAKE_CXX_STANDARD 17)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

include(CTest)

find_package(Catch2 2.8 REQUIRED)
include(Catch)
add_library(catch_entry test_entry.cpp)
target_link_libraries(catch_entry PUBLIC Catch2::Catch2)

set(BUILD_SHARED_LIBS ON) # need for Boost::system
find_package(Boost 1.68 REQUIRED COMPONENTS system)

add_subdirectory(lab1)
add_subdirectory(lab2)
add_subdirectory(lab3)
add_subdirectory(lab4)
add_subdirectory(lab5)
add_subdirectory(lab6)
add_subdirectory(lab7)
add_subdirectory(lab8)
