# test 0: just succeeds, for ctest
add_executable(alwaysSuccess test_alwaysSuccess.cpp)
add_executable(TEST::SUCCESS ALIAS alwaysSuccess)
target_link_libraries(alwaysSuccess UTIL::COMPILEOPTIONS)

# test 1: parse 3 simple execution examples 
add_executable(calculateCalibrationExamples test_calculateCalibrationExamples.cpp)
add_executable(TEST::calculateCalibrationExamples ALIAS calculateCalibrationExamples)
target_include_directories(calculateCalibrationExamples PRIVATE ../include)
target_link_libraries(calculateCalibrationExamples UTIL::COMPILEOPTIONS)
target_link_libraries(calculateCalibrationExamples AOC::TREBUCHET)

# test 2: parse just strings, we use this to parse corner cases from our examples
add_executable(trebuchetParseCalibrationString test_parseCalibrationString.cpp)
add_executable(TEST::trebuchetParseCalibrationString ALIAS trebuchetParseCalibrationString)
target_include_directories(trebuchetParseCalibrationString PRIVATE ../include)
target_link_libraries(trebuchetParseCalibrationString UTIL::COMPILEOPTIONS)
target_link_libraries(trebuchetParseCalibrationString AOC::TREBUCHET)

add_executable(trebuchetConvertStrings test_stringConvert.cpp)
add_executable(TEST::trebuchetConvertStrings ALIAS trebuchetConvertStrings)
target_include_directories(trebuchetConvertStrings PRIVATE ../include)
target_link_libraries(trebuchetConvertStrings UTIL::COMPILEOPTIONS)
target_link_libraries(trebuchetConvertStrings AOC::TREBUCHET)

add_executable(trebuchetDigits test_trebuchetDigits.cpp)
add_executable(TEST::trebuchetDigits ALIAS trebuchetDigits)
target_include_directories(trebuchetDigits PRIVATE ../include)
target_link_libraries(trebuchetDigits UTIL::COMPILEOPTIONS)
target_link_libraries(trebuchetDigits AOC::TREBUCHET)



# collect all tests for ctest
add_test(
  NAME TrebuchetConvertString
  COMMAND
    TEST::trebuchetConvertStrings --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::trebuchetConvertStrings --test-command
    "${CMAKE_CTEST_COMMAND}")

add_test(
  NAME "Trebuchet Parse Calibration String"
  COMMAND
    TEST::trebuchetParseCalibrationString --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::trebuchetParseCalibrationString --test-command
    "${CMAKE_CTEST_COMMAND}")

add_test(
  NAME "Trebuchet Calculate Calibration Examples"
  COMMAND
    TEST::calculateCalibrationExamples --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::calculateCalibrationExamples --test-command
    "${CMAKE_CTEST_COMMAND}")

add_test(
  NAME "Trebuchet D1C2 Digits"
  COMMAND
    TEST::trebuchetDigits --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::trebuchetDigits --test-command
    "${CMAKE_CTEST_COMMAND}")

add_test(
  NAME TrebuchetSuccess
  COMMAND
    TEST::SUCCESS --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_BINARY_DIR}/test" --build-generator "${CMAKE_GENERATOR}"
    --build-project TEST::SUCCESS --test-command "${CMAKE_CTEST_COMMAND}")
