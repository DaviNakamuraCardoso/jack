#include "hash.h"
#include "list.h"

#ifndef __TOKENSH
#define __TOKENSH

enum command { 
    PUSH    =   0, 
    POP     =   1,
    LABEL   =   2,
    GOTO    =   3,
    IFGOTO  =   4,
    CALL    =   5,
    FUNCTION=   6,
    RETURN  =   7,
    ADD     =   8,
    SUB     =   9,
    MULT    =   10,
    DIV     =   11,
    GT      =   12,
    LT      =   13,
    EQ      =   14, 
    NOT     =   15, 
    AND     =   16,
    OR      =   17
}; 

enum memseg {
    CONSTANT        =   0, 
    STATIC          =   1,
    ARGUMENT        =   2,
    LOCAL           =   3, 
    THIS            =   4,
    THAT            =   5,
    POINTER         =   6,
    TEMP            =   7
};

typedef struct _source {
    List* tokens;
    Hash** cmds;
    Hash** memsegs;
    Map* indexes;
    unsigned long *labels;
    unsigned long staticcount, stdcount; 
} Source;

    
Source* new_source(void);
void release_source(Source* s);


#endif 
