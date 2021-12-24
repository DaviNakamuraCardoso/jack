#include <stdio.h>
#include <stdlib.h>

optree_t *opnew(void)
{
    optree_t *t = malloc(sizeof(optree_t));

    for (unsigned int i = 0; i < SYMBOL_MAX; i++) t->nodes[i] = NULL; 
    t->exists = 0;

    return t;
}

unsigned int opdestroy(optree_t *t)
{
    for (unsigned int i = 0; i < SYMBOL_MAX; i++)
    {
        opdestroy(t->nodes[i]);
    }

    free(t);
    return 0;
}

optree_t* opget(optree_t *t, char *operator)
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

unsigned int opadds(optree_t *t, char *operator, unsigned int type)
{
    optree_t *current = t;

    for (int i = 0; operator[i] != '\0'; i++)
    {
        unsigned int index = opindex(operator[i]);

        if (current->nodes[index] == NULL)
        {
            current->nodes[index] = opnew(); 
        }

        current = current->nodes[index];
    }

    current->exists = 1;
    current->value = type;
    
    return 0; 
}



