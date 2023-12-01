# add a generic target to provide compiler definitions
add_library(
    generic_target
    INTERFACE
)
add_library(UTIL::COMPILEOPTIONS ALIAS generic_target)

set(MY_DEBUG_OPTIONS "-O1 -g3 --std=c++11 -DDEBUG")
set(MY_RELEASE_OPTIONS "-O3 -g1 --std=c++11 -DNDEBUG")
target_compile_options(generic_target INTERFACE "$<$<CONFIG:DEBUG>:SHELL:${MY_DEBUG_OPTIONS}>")
target_compile_options(generic_target INTERFACE "$<$<CONFIG:RELEASE>:SHELL:${MY_RELEASE_OPTIONS}>")

