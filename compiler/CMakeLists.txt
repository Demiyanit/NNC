cmake_minimum_required(VERSION 3.22)

project(Compiler
    VERSION 0.0.1
    LANGUAGES C CXX
)

if(MSVC)
    add_compile_options(
        /W4 # Enable all warnings.
        # Don't suggest the _s nonsence functions.
        /D_CRT_SECURE_NO_WARNINGS
        /D_CRT_SECURE_NO_WARNINGS_GLOBALS
        /D_CRT_NONSTDC_NO_WARNINGS
    )
else()
    add_compile_options(
        -Wall
        -Werror=return-type
        -Wshadow
        -Wconversion
        -Wno-unused
        
        -g
        -D_CRT_SECURE_NO_WARNINGS
    )
    
endif()

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS
    "src/*"
    "include/*"
)



add_library(Compiler SHARED ${SRCS})
set_property(TARGET Compiler PROPERTY C_STANDARD 17)
set_property(TARGET Compiler PROPERTY CXX_STANDARD 17)
set_property(TARGET Compiler PROPERTY C_STANDARD_REQUIRED true)
set_property(TARGET Compiler PROPERTY CXX_STANDARD_REQUIRED true)

target_compile_definitions(Compiler PRIVATE SKL_EXPORT)

target_include_directories(Compiler PUBLIC 
    "src"
    "include"
)