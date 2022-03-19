#ifndef __MACROTABLE_H
#define __MACROTABLE_H

#include "tokens.h"

typedef struct mtable mtable_t;

typedef struct mnode {
    char*  macro;
    size_t length;
    token_t** ts;
    struct mnode *next;
} mnode_t;


mtable_t*     mtnew(void);
mnode_t*      mtset(mtable_t*, char*, token_t**s, size_t);
mnode_t*      mtget(mtable_t*, char*);


#endif
