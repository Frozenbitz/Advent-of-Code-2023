# test 0: just succeeds, for ctest
add_executable(alwaysSuccess test_alwaysSuccess.cpp)
add_executable(TEST::SUCCESS ALIAS alwaysSuccess)
target_link_libraries(alwaysSuccess UTIL::COMPILEOPTIONS)

# test 1: parse 3 simple execution examples 
add_executable(token test_token.cpp)
add_executable(TEST::token ALIAS token)
target_include_directories(token PRIVATE ../include)
target_link_libraries(token UTIL::COMPILEOPTIONS)
target_link_libraries(token AOC::gears)

add_executable(bitmap test_Bitmap.cpp)
add_executable(TEST::bitmap ALIAS bitmap)
target_include_directories(bitmap PRIVATE ../include)
target_link_libraries(bitmap UTIL::COMPILEOPTIONS)
target_link_libraries(bitmap AOC::gears)

add_executable(moreBitmap test_Bitmap2.cpp)
add_executable(TEST::moreBitmap ALIAS moreBitmap)
target_include_directories(moreBitmap PRIVATE ../include)
target_link_libraries(moreBitmap UTIL::COMPILEOPTIONS)
target_link_libraries(moreBitmap AOC::gears)

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
  NAME "create and verify Token"
  COMMAND
    TEST::token --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::token --test-command "${CMAKE_CTEST_COMMAND}")

add_test(
    NAME "create and parse a simple bitmap"
    COMMAND
      TEST::bitmap --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
      "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
      --build-project TEST::bitmap --test-command "${CMAKE_CTEST_COMMAND}")

add_test(
  NAME "create a very small bitmap"
  COMMAND
    TEST::moreBitmap --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::moreBitmap --test-command "${CMAKE_CTEST_COMMAND}")