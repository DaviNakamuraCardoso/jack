#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <macrotable.h>

#define MTSIZE 101

typedef struct mtnode {
    char *macro;
    size_t value;
    struct mtnode *next;
} mnode_t;

struct mtable {
    mnode_t *nodes[MTSIZE];
};


/**
 * The C Programming Language
 */
static size_t hash(char* s)
{ 
    size_t hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    
    return hashval;
}

mtable_t *mtnew(void)
{
    mtable_t* mt = malloc(sizeof(mtable_t));
    for (size_t i = 0; i < MTSIZE; i++) mt->nodes[i] = NULL;

    return mt;
}

mnode_t *mnnew(char* s, size_t v)
{
    mnode_t *n = malloc(sizeof(mnode_t));
    n->macro = strdup(s);
    n->value = v;

    return n;
}


size_t mtset(mtable_t *mt, char *macro, size_t value)
{
    size_t index = hash(macro);
    mnode_t *first = mt->nodes[index];
    mt->nodes[index] = mnnew(macro, value);
    mt->nodes[index]->next = first;

    return value;
} 

size_t mtget(mtable_t *mt, char* macro)
{
    size_t index = hash(macro);

    for (mnode_t *n = mt->nodes[index]; n != NULL; n = n->next) if (strcmp(n->macro, macro) == 0) return n->value;

    return 0;
}



