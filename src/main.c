#include <stdio.h>
#include <nnc/utils/vector.h>
#include <nnc/utils/string.h>

#include <nnc/lexer.h>
#include <nnc/file.h>

const char* version = "0.0.1";

void display_usage(char** argv) {
    printf("No Name Compiler V%s\n"\
            "Right now it does not even compile...\n"\
            "Usage:\n"\
            "%s <filename>\n",
            version, argv[0]);
}

int main(int argc, char** argv) {
    if(argc < 2 || argv[1][0] == '-' && argv[1][1] == 'h') {
        display_usage(argv);
        return 0;
    }

    nnc_file file = load_file(argv[1]);



    destroy_file(&file);

   
    

    return 0;
}