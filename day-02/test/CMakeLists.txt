# test 0: just succeeds, for ctest
add_executable(alwaysSuccess test_alwaysSuccess.cpp)
add_executable(TEST::SUCCESS ALIAS alwaysSuccess)
target_link_libraries(alwaysSuccess UTIL::COMPILEOPTIONS)

# test 1: parse 3 simple execution examples 
add_executable(createToken test_tokenInit.cpp)
add_executable(TEST::createToken ALIAS createToken)
target_include_directories(createToken PRIVATE ../include)
target_link_libraries(createToken UTIL::COMPILEOPTIONS)
target_link_libraries(createToken AOC::cubeConundrum)

add_executable(createGame test_gameInit.cpp)
add_executable(TEST::createGame ALIAS createGame)
target_include_directories(createGame PRIVATE ../include)
target_link_libraries(createGame UTIL::COMPILEOPTIONS)
target_link_libraries(createGame AOC::cubeConundrum)

add_executable(cunundrumInit test_cunundrumInit.cpp)
add_executable(TEST::cunundrumInit ALIAS cunundrumInit)
target_include_directories(cunundrumInit PRIVATE ../include)
target_link_libraries(cunundrumInit UTIL::COMPILEOPTIONS)
target_link_libraries(cunundrumInit AOC::cubeConundrum)


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

add_test(
  NAME "Initialize a Game-Token"
  COMMAND
    TEST::createToken --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::createToken --test-command "${CMAKE_CTEST_COMMAND}")

add_test(
  NAME "Initialize a single Game instance"
  COMMAND
    TEST::createGame --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::createGame --test-command "${CMAKE_CTEST_COMMAND}")

add_test(
  NAME "Initialize a cubeConundrum instance"
  COMMAND
    TEST::cunundrumInit --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::cunundrumInit --test-command "${CMAKE_CTEST_COMMAND}")