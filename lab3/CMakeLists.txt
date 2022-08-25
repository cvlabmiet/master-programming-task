return() # Remove this line
find_package(Threads REQUIRED)

add_library(proxy INTERFACE)
target_include_directories(proxy INTERFACE include)
target_link_libraries(proxy INTERFACE Threads::Threads)

file(GLOB TESTS tests/*.cpp)
add_executable(tests_proxy ${TESTS})
target_link_libraries(tests_proxy proxy Catch2::Catch2WithMain Boost::boost)
catch_discover_tests(tests_proxy)
