return() # Remove this line
add_library(introduction INTERFACE)
target_include_directories(introduction INTERFACE include)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_introduction ${TESTS})
target_link_libraries(tests_introduction introduction catch_entry)
catch_discover_tests(tests_introduction)
