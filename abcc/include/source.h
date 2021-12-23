#ifndef __SOURCE_H
#define __SOURCE_H

typedef struct source 
{
    FILE* f;
    char* buff;
    const char* filename; 

} source_t;


#endif
