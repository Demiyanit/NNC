#include <stdio.h>
#include <stdlib.h>
#include <util/filesystem.h>

static size_t get_file_size(FILE* f) {
    size_t size = 0;
    fseek(f, 0L, SEEK_END);
    size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    return size;
}

file_handle* load_file(const char* path) {
    file_handle* ret = malloc(sizeof(file_handle));

     

    return ret;
}

void destroy_file(file_handle* file) {

}