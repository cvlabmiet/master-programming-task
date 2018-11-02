cmake_minimum_required(VERSION 3.9)

include(CTest)

add_compile_options(-Wall -Wextra -pedantic -Werror)

file(GLOB _files LIST_DIRECTORIES TRUE *)

foreach(_file ${_files})
    if(IS_DIRECTORY ${_file} AND EXISTS "${_file}/CMakeLists.txt")
        message(STATUS "Add subproject ${_file}")
        add_subdirectory(${_file})
    endif()
endforeach()

find_program(AWK_EXECUTABLE awk gawk DOC "awk executable")
file(GLOB_RECURSE SRCS *.hpp)
add_custom_target(encrypt COMMAND ${AWK_EXECUTABLE} -i inplace -v enc=1 -f ${CMAKE_SOURCE_DIR}/encrypt.awk ${SRCS})
add_custom_target(decrypt COMMAND ${AWK_EXECUTABLE} -i inplace -v enc=0 -f ${CMAKE_SOURCE_DIR}/encrypt.awk ${SRCS})

add_custom_target(answer COMMAND ${CMAKE_COMMAND} -DSOURCE_DIR=${CMAKE_SOURCE_DIR} -P ${CMAKE_SOURCE_DIR}/find_answers.cmake)
