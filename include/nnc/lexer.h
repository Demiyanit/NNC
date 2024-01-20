#ifndef _NNC_LEXER_H_
#define _NNC_LEXER_H_

#include <nnc/utils/vector.h>
#include <nnc/utils/string.h>
#include <nnc/file.h>

typedef enum toket_type {
    TOKEN_TYPE_TYPE,
    TOKEN_TYPE_PCOMMA,
    TOKEN_TYPE_OPAREN,
    TOKEN_TYPE_CPAREN,
    TOKEN_TYPE_OCURLY,
    TOKEN_TYPE_CCURLY,
    TOKEN_TYPE_NAME,
    TOKEN_TYPE_VARIABLE,
    TOKEN_TYPE_FUNCTION,
    TOKEN_TYPE_EOF,
    TOKEN_TYPE_UNKNOWN
} token_type;

typedef struct token {
    token_type type;
    char* position;
    unsigned long long length;
} token;

token lex_next(char* data);
// returns a vector of strings, can be destroyed manually, but when you are doing this, dont forget to destroy strings in it
vector splice_strings(const char* data);
void splice_strings_destroy_vector(vector *v);

#endif//_NNC_LEXER_H_