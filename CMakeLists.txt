cmake_minimum_required(VERSION 3.15)
project(cxx-tasks VERSION 0.2.1 LANGUAGES CXX DESCRIPTION "Home tasks for C++ training")

set(CMAKE_CXX_STANDARD 20)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

find_package(Catch2 3 REQUIRED)
find_package(Boost 1.79 REQUIRED)

include(CTest)
include(Catch)

add_subdirectory(lab1)
add_subdirectory(lab2)
add_subdirectory(lab3)
add_subdirectory(lab4)
add_subdirectory(lab5)
add_subdirectory(lab6)
add_subdirectory(lab7)
add_subdirectory(lab8)
