cmake_minimum_required(VERSION 3.12)
project(cxx-tasks VERSION 0.2.0 LANGUAGES CXX DESCRIPTION "Home tasks for C++ training")

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

add_subdirectory(iomanip)
add_subdirectory(proxy)
add_subdirectory(iterator)
add_subdirectory(variant)
add_subdirectory(type_map)
add_subdirectory(csv_parser)
add_subdirectory(json_parser)
add_subdirectory(strided_range)

file(GLOB_RECURSE SRCS *.hpp)
add_custom_target(encrypt COMMAND ${CMAKE_COMMAND} "-DSRCS=\"${SRCS}\"" -DENC=TRUE -P ${CMAKE_SOURCE_DIR}/crypt.cmake)
add_custom_target(decrypt COMMAND ${CMAKE_COMMAND} "-DSRCS=\"${SRCS}\"" -DENC=FALSE -P ${CMAKE_SOURCE_DIR}/crypt.cmake)

add_custom_target(answer COMMAND ${CMAKE_COMMAND} -DSOURCE_DIR=${CMAKE_SOURCE_DIR} -P ${CMAKE_SOURCE_DIR}/find_answers.cmake)
