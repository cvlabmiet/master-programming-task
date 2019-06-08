add_library(parser_helper INTERFACE)
target_include_directories(parser_helper INTERFACE include)
target_link_libraries(parser_helper INTERFACE Boost::boost Boost::system)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_parser_helper ${TESTS})
target_link_libraries(tests_parser_helper parser_helper catch_entry)
catch_discover_tests(tests_parser_helper)
