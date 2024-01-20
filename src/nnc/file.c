#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <nnc/file.h>

nnc_file load_file(const char* path) {
    nnc_file ret = {0};
    FILE* f = fopen(path, "rb");
    if(ferror(f)) {
        printf("[ERROR #%d]: Failed to open a file at path: %s", ferror(f), path); 
        fclose(f); 
        return (nnc_file) {0}; 
    }

    fseek(f, 0, SEEK_END);
    ret.file_length = ftell(f);
    fseek(f, 0, SEEK_SET);
    if(ferror(f)) { 
        printf("[ERROR #%d]: Failed to get the file size at path: %s", ferror(f), path); 
        fclose(f); 
        return (nnc_file) {0}; 
    }

    ret.file_data = malloc(sizeof(char) * ret.file_length + 1);
    if(ret.file_data == NULL) {
        printf("[ERROR #%d]: Failed to allocate data for a file at path: %s", ferror(f), path); 
        fclose(f); 
        return (nnc_file) {0};
    }

    memset(ret.file_data, 0, ret.file_length);
    ret.file_data[ret.file_length] = '\0';
    fread(ret.file_data, 1, ret.file_length, f);
    if(ferror(f)) {
        printf("[ERROR #%d]: Failed to read file at path: %s", ferror(f), path); 
        free(ret.file_data); 
        fclose(f); 
        return (nnc_file) {0};
    }

    fclose(f);
    return ret;
}

void destroy_file(nnc_file* file_ptr) {
    free(file_ptr->file_data);
    file_ptr->file_data = 0;
    file_ptr->file_length = 0;
}