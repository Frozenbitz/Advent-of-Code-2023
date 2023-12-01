cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 11)


project(AoC-day1-challenge1 LANGUAGES CXX)

# todo:  clear all c and C++ flags before compilation, since we want to set those up

# gather unit tests and execute them
add_subdirectory(test)

# include helpers
include(cmake/genericTarget.cmake)

# add the main class for this assignment
add_library(
    trebuchet 
    src/trebuchet.cpp
)
target_include_directories(trebuchet PUBLIC include)
target_link_libraries(trebuchet UTIL::COMPILEOPTIONS)

# this will be used to call the main class & to separate code for testing into the trebuchet class
add_executable(
        aoc-d1c1
        src/main.cpp
)
target_include_directories(aoc-d1c1 PUBLIC inlcude)
target_link_libraries(aoc-d1c1 UTIL::COMPILEOPTIONS)

# execute current target in a shell after successfull compilation
add_custom_target(run
    COMMAND aoc-d1c1
    DEPENDS aoc-d1c1
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)