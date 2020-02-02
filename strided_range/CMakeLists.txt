return() # Remove this line
add_library(strided_range INTERFACE)
target_include_directories(strided_range INTERFACE include)
target_link_libraries(strided_range INTERFACE Boost::boost)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_strided_range ${TESTS})
target_link_libraries(tests_strided_range strided_range catch_entry)
catch_discover_tests(tests_strided_range)
