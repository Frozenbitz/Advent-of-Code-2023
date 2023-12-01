include(CTest)

enable_testing()

# define a simple test 
add_executable(alwaysSuccess mainFixture.cpp)
add_executable(TEST::SUCCESS ALIAS alwaysSuccess)


# define a new test for trebuchet input data
add_executable(trebuchetSimple trebuchet.cpp)
add_executable(TEST::trebuchetSimple ALIAS trebuchetSimple)

# collect all tests for ctest
add_test(NAME SimpleTest COMMAND TEST::SUCCESS)
add_test(NAME Trebuchet COMMAND TEST::trebuchetSimple)