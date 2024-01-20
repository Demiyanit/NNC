#include <stdio.h>
#include <compiler.h>


int SKL_API _temp_main(int argc, char** argv) {
    
    SKLDEBUG("Number of arguments: %d, arguments:", argc);
    for (size_t i = 0; i < argc; i++) {
        SKLDEBUG("%s", argv[i]);
    }

    return argc > 2 ? 0 : -1;
}