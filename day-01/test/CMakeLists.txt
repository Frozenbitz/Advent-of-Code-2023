# test 0: just succeeds, for ctest
add_executable(alwaysSuccess test_alwaysSuccess.cpp)
add_executable(TEST::SUCCESS ALIAS alwaysSuccess)
target_link_libraries(alwaysSuccess UTIL::COMPILEOPTIONS)

# test 1: parse 3 simple execution examples 
add_executable(trebuchetSimple test_calculateCalibrationExamples.cpp)
add_executable(TEST::trebuchetSimple ALIAS trebuchetSimple)
target_include_directories(trebuchetSimple PRIVATE ../include)
target_link_libraries(trebuchetSimple UTIL::COMPILEOPTIONS)
target_link_libraries(trebuchetSimple AOC::TREBUCHET)

# test 2: parse just strings, we use this to parse corner cases from our examples
add_executable(trebuchetString test_parseCalibrationString.cpp)
add_executable(TEST::trebuchetString ALIAS trebuchetString)
target_include_directories(trebuchetString PRIVATE ../include)
target_link_libraries(trebuchetString UTIL::COMPILEOPTIONS)
target_link_libraries(trebuchetString AOC::TREBUCHET)

# test 2: parse just strings, we use this to parse corner cases from our examples
add_executable(trebuchetConvertStrings test_stringConvert.cpp)
add_executable(TEST::trebuchetConvertStrings ALIAS trebuchetConvertStrings)
target_include_directories(trebuchetConvertStrings PRIVATE ../include)
target_link_libraries(trebuchetConvertStrings UTIL::COMPILEOPTIONS)
target_link_libraries(trebuchetConvertStrings AOC::TREBUCHET)



# collect all tests for ctest
add_test(
  NAME TrebuchetConvertString
  COMMAND
    TEST::trebuchetConvertStrings --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::trebuchetConvertStrings --test-command
    "${CMAKE_CTEST_COMMAND}")

add_test(
  NAME TrebuchetParseString
  COMMAND
    TEST::trebuchetString --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::trebuchetString --test-command
    "${CMAKE_CTEST_COMMAND}")

add_test(
  NAME TrebuchetCalculate
  COMMAND
    TEST::trebuchetSimple --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::trebuchetSimple --test-command
    "${CMAKE_CTEST_COMMAND}")

add_test(
  NAME TrebuchetSuccess
  COMMAND
    TEST::SUCCESS --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::SUCCESS --test-command "${CMAKE_CTEST_COMMAND}")
