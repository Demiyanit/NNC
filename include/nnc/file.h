#ifndef _NNC_FILE_H_
#define _NNC_FILE_H_

typedef struct nnc_file{
    char* file_data;
    unsigned long long file_length;
} nnc_file;


nnc_file load_file(const char* path);
void destroy_file(nnc_file* file_ptr);


#endif//_NNC_FILE_H_