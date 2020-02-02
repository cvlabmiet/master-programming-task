return() # Remove this line
add_library(variant INTERFACE)
target_include_directories(variant INTERFACE include)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_variant ${TESTS})
target_link_libraries(tests_variant variant catch_entry Boost::boost)
catch_discover_tests(tests_variant)
