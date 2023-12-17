cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)


project(AoC-day2 LANGUAGES CXX)

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
add_library(cubeConundrum src/cubeConundrum.cpp src/token.cpp)
add_library(AOC::cubeConundrum ALIAS cubeConundrum)
target_include_directories(cubeConundrum PUBLIC include)
target_link_libraries(cubeConundrum UTIL::COMPILEOPTIONS)

# this will be used to call the main class & to separate code for testing into the trebuchet class
add_executable(aoc-day2 src/main.cpp)
target_link_libraries(aoc-day2 UTIL::COMPILEOPTIONS)
target_link_libraries(aoc-day2 AOC::cubeConundrum)

# create a local copy of all our test files in the binary subdir, this allows us to call all tests from within the bin-dir 
# with relative paths
set(EXAMPLE_PATH "${CMAKE_SOURCE_DIR}/examples")
file(COPY ${EXAMPLE_PATH} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
