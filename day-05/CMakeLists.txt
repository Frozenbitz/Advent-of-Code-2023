cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)


project(AoC-day5 LANGUAGES CXX)

# todo:  clear all c and C++ flags before compilation, since we want to set those up

# gather unit tests and execute them
include(CTest)
enable_testing()
add_subdirectory(test)

# include helpers
include(cmake/genericTarget.cmake)

# parse configure file to include relevant test data for the first challenge
# configure_file (
#     "cmake/config.h.in"
#     "include/config.h"
# )


# add the main class for this assignment
add_library(mapper   src/statemachine.cpp)
add_library(AOC::mapper ALIAS mapper)
target_include_directories(mapper PUBLIC include)
target_link_libraries(mapper UTIL::COMPILEOPTIONS)

# this will be used to call the main class & to separate code for testing into the trebuchet class
add_executable(aoc-day5 src/main.cpp)
target_link_libraries(aoc-day5 UTIL::COMPILEOPTIONS)
target_link_libraries(aoc-day5 AOC::mapper)


# create a local copy of all our test files in the binary subdir, this allows us to call all tests from within the bin-dir 
# with relative paths
set(EXAMPLE_PATH "${CMAKE_SOURCE_DIR}/examples")
file(COPY ${EXAMPLE_PATH} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
