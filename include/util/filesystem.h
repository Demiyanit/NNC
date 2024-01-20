#ifndef _SKL_FILESYSTEM_H_
#define _SKL_FILESYSTEM_H_

typedef struct file_handle {
    char* content;
    int size;
} file_handle;

file_handle* load_file(const char* path);
void destroy_file(file_handle* file);

#endif//_SKL_FILESYSTEM_H_