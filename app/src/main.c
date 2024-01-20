#include <compiler.h>

int main(int argc, char** argv) {
    int number_of_args = 2;
    (void*)argc;
    char* args[] = {
        argv[0],
        "test.skl"
    };

    SKLFATAL("TEST FATAL MESSAGE");
    SKLERROR("TEST ERROR MESSAGE");
    SKLWARN ("TEST WARN  MESSAGE");
    SKLINFO ("TEST INFO  MESSAGE");
    SKLDEBUG("TEST DEBUG MESSAGE");
    SKLTRACE("TEST TRACE MESSAGE");

    int result = _temp_main(number_of_args, args);

    return result;
}