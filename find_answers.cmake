# Arguments: SOURCE_DIR
# Call: cmake -DSOURCE_DIR=$PWD -P find_answers.cmake

if(NOT SOURCE_DIR)
    set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})
endif()

file(GLOB_RECURSE SRCS ${SOURCE_DIR}/*.[hc]pp)
foreach(_file ${SRCS})
    file(STRINGS ${_file} _lines REGEX "^[ \\t]*//(\\?|!)" ENCODING UTF-8)
    foreach(_line ${_lines})
        string(STRIP "${_line}" _line)
        string(REPLACE "//?" "Q:" _line "${_line}")
        string(REPLACE "//!" "  A:" _line "${_line}")
        message("${_line}")
    endforeach()
endforeach()
