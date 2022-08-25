return() # Remove this line
add_library(introduction INTERFACE)
target_include_directories(introduction INTERFACE include)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_introduction ${TESTS})
target_link_libraries(tests_introduction introduction Catch2::Catch2WithMain)
catch_discover_tests(tests_introduction)
