#include <stdio.h>
#include <stdlib.h>
#include <optree.h>

optree_t *opnew(void)
{
    optree_t *t = malloc(sizeof(optree_t));

    for (unsigned int i = 0; i < __SYM_COUNT; i++) t->nodes[i] = NULL; 
    t->exists = 0;
    t->isoperator = 0;

    return t;
}

unsigned int opdestroy(optree_t *t)
{
    if (t == NULL) return 0;

    for (unsigned int i = 0; i < __SYM_COUNT; i++)
    {
        opdestroy(t->nodes[i]);
    }

    free(t);
    return 0;
}

optree_t* opgets(optree_t *t, char *operator)
{
    optree_t *current = t;
    char c;
    
    for (int i = 0; (c = operator[i]) != '\0'; i++)
    {
        current = t->nodes[opindex(c)]; 
        if (current == NULL) return NULL;
    } 
    
    return t;
}

unsigned int opadds(optree_t *t, const char *operator, unsigned int type)
{
    optree_t *current = t;

    for (int i = 0; operator[i] != '\0'; i++)
    {
        symbol_e index = opindex(operator[i]); 

        if (current->nodes[index] == NULL)
        {
            current->nodes[index] = opnew(); 
        }

        current = current->nodes[index];
    }

    current->exists = 1;
    current->isoperator = 1;
    current->operator = type;
    
    return 0; 
}

unsigned int opaddc(optree_t *t, char c)
{
    unsigned int index = opindex(c);
    if (index == __SYM_COUNT) return 1;

    optree_t* node = opnew();
    node->exists = 1;
    node->symbol = index;
    t->nodes[index] = node;

    return 0;
} 
   

optree_t* opgetc(optree_t *t, char c)
{
    symbol_e index = opindex(c);
    if (index == __SYM_COUNT) return NULL;

    return t->nodes[index]; 
} 

