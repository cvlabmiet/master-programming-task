return() # Remove this line
add_library(type_map INTERFACE)
target_include_directories(type_map INTERFACE include)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_type_map ${TESTS})
target_link_libraries(tests_type_map type_map catch_entry)
catch_discover_tests(tests_type_map)
