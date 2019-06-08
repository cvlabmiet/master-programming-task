add_library(iomanip INTERFACE)
target_include_directories(iomanip INTERFACE include)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_iomanip ${TESTS})
target_link_libraries(tests_iomanip iomanip catch_entry)
catch_discover_tests(tests_iomanip)
