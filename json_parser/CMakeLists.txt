if(NOT TARGET parser_helper)
    add_subdirectory(${CMAKE_SOURCE_DIR}/parser_helper ${CMAKE_BINARY_DIR}/parser_helper)
endif()

add_library(json_parser INTERFACE)
target_include_directories(json_parser INTERFACE include)
target_link_libraries(json_parser INTERFACE parser_helper)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_json_parser ${TESTS})
target_link_libraries(tests_json_parser json_parser catch_entry)
catch_discover_tests(tests_json_parser)
