cmake_minimum_required(VERSION 3.22)

project(App
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

file(GLOB_RECURSE SRCS
    "${PROJECT_SOURCE_DIR}/src/*"
    "${PROJECT_SOURCE_DIR}/include/*"
)


add_executable(App ${SRCS})
set_property(TARGET App PROPERTY C_STANDARD 17)
set_property(TARGET App PROPERTY CXX_STANDARD 17)
set_property(TARGET App PROPERTY C_STANDARD_REQUIRED true)
set_property(TARGET App PROPERTY CXX_STANDARD_REQUIRED true)

target_link_libraries(App Compiler)

target_include_directories(App PUBLIC 
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/include"
    "${CMAKE_SOURCE_DIR}/compiler/include"
)

add_custom_command(TARGET App POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   $<TARGET_FILE:Compiler>
                   $<TARGET_FILE_DIR:App>)