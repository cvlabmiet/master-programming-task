if(NOT TARGET parser_helper)
    add_subdirectory(${CMAKE_SOURCE_DIR}/parser_helper ${CMAKE_BINARY_DIR}/parser_helper)
endif()

add_library(csv_parser INTERFACE)
target_include_directories(csv_parser INTERFACE include)
target_link_libraries(csv_parser INTERFACE parser_helper)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_csv_parser ${TESTS})
target_link_libraries(tests_csv_parser csv_parser catch_entry)
catch_discover_tests(tests_csv_parser)
