#ifndef __TOKENIZERH
#define __TOKENIZERH

#define BUFF_MAX 1000

#include "tokens.h"
#include "ascii.h" 
#include "operators.h"

typedef struct source 
{
    FILE* fd;
    char buff[BUFF_MAX];
    const char* filename; 

} source_t;

token_t** tokenize(FILE* f);

#endif

