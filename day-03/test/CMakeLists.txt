# test 0: just succeeds, for ctest
add_executable(alwaysSuccess test_alwaysSuccess.cpp)
add_executable(TEST::SUCCESS ALIAS alwaysSuccess)
target_link_libraries(alwaysSuccess UTIL::COMPILEOPTIONS)

# test 1: parse 3 simple execution examples 
# add_executable(createToken test_tokenInit.cpp)
# add_executable(TEST::createToken ALIAS createToken)
# target_include_directories(createToken PRIVATE ../include)
# target_link_libraries(createToken UTIL::COMPILEOPTIONS)
# target_link_libraries(createToken AOC::cubeConundrum)


# create a local copy of all our test files in the binary subdir, this allows us to call all tests from within the bin-dir 
# with relative paths
set(TEST_DATA_PATH "${CMAKE_CURRENT_SOURCE_DIR}/testdata")
file(COPY ${TEST_DATA_PATH} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


# collect all tests for ctest
add_test(
  NAME "Always Success"
  COMMAND
    TEST::SUCCESS --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::SUCCESS --test-command "${CMAKE_CTEST_COMMAND}")