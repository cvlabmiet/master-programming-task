# -DSRCS, -DENC

cmake_policy(SET CMP0007 NEW) # do not ignore empty elements in lists

find_program(OPENSSL openssl DOC "openssl executable")

file(READ "password" _password)
string(REGEX MATCH "[^ ]+" _password ${_password})

foreach(_file ${SRCS})
    file(STRINGS ${_file} _lines)
    set(_in_block FALSE)
    unset(_content)

    foreach(_line IN LISTS _lines)
        if(_line MATCHES "//}")
            set(_in_block FALSE)
        endif()

        string(LENGTH "${_line}" _length)
        if(_in_block AND _length GREATER 0)
            string(REGEX MATCH "^[ \t]+" _spaces ${_line})
            string(STRIP "${_line}" _line)
            file(WRITE "line_cache" "${_line}")

            if(ENC)
                execute_process(COMMAND ${OPENSSL} enc -aes-128-cbc -e -pbkdf2 -iter 1000 -a -A -K ${_password}
                    -iv ${_password} INPUT_FILE "line_cache" OUTPUT_VARIABLE _line)
            else()
                execute_process(COMMAND ${OPENSSL} enc -aes-128-cbc -d -pbkdf2 -iter 1000 -a -A -K ${_password}
                    -iv ${_password} INPUT_FILE "line_cache" OUTPUT_VARIABLE _line)
            endif()

            string(STRIP "${_line}" _line)
            set(_line "${_spaces}${_line}")
        endif()

        if(_line MATCHES "//{")
            set(_in_block TRUE)
        endif()

        set(_content "${_content}${_line}\n")
    endforeach()

    file(WRITE "${_file}" "${_content}")
endforeach()
