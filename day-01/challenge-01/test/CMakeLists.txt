# define a simple test 
add_executable(alwaysSuccess mainFixture.cpp)
add_executable(TEST::SUCCESS ALIAS alwaysSuccess)
target_link_libraries(alwaysSuccess UTIL::COMPILEOPTIONS)


# define a new test for trebuchet input data
add_executable(trebuchetSimple trebuchet.cpp)
add_executable(TEST::trebuchetSimple ALIAS trebuchetSimple)
target_include_directories(trebuchetSimple PRIVATE ../include)
target_link_libraries(trebuchetSimple UTIL::COMPILEOPTIONS)
target_link_libraries(trebuchetSimple AOC::TREBUCHET)

# collect all tests for ctest
add_test(NAME SimpleTest COMMAND TEST::SUCCESS)
add_test(NAME Trebuchet COMMAND TEST::trebuchetSimple)