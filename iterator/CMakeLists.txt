return() # Remove this line
add_library(iterator INTERFACE)
target_include_directories(iterator INTERFACE include)
target_link_libraries(iterator INTERFACE Boost::boost)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_iterator ${TESTS})
target_link_libraries(tests_iterator iterator catch_entry)
catch_discover_tests(tests_iterator)
