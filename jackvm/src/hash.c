#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hash.h>

#define HASHSIZE 300


Hash** new_hash(void)
{
    Hash **h = calloc(sizeof(Hash*), HASHSIZE);
    for (int i = 0; i < HASHSIZE; i++)
    {
        h[i] = NULL; 
    }

    return h;
}

Map* new_map(void)
{
    Map *m = malloc(sizeof(Map));
    m->hash = new_hash();
    m->counter = 1;

    return m;
}

Hash* new_hashnode(char* key, short type)
{
    Hash* hn = malloc(sizeof(Hash));
    hn->key = strdup(key);
    hn->type = type; 

    return hn; 
} 

unsigned int hash(char* key)
{
     
    unsigned int val = 0; 
    for (char *c = key; *c != '\0'; c++)
        val += (*c) * 31; 

    return val % HASHSIZE; 
}

void add_hash(Hash** h, char* key, short value)
{
    Hash *hn, *new = new_hashnode(key, value);
    int index = hash(key);
    if (h[index] == NULL)
    {
        h[index] = new;
        return;
    }

    hn = h[index];
    h[index] = new; 
    new->next = hn;
    return;
}

void add_map(Map* m, char* key)
{
    add_hash(m->hash, key, m->counter++);
}

unsigned int strmatch(char* s1, char* s2)
{
    int i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i]) return 0;

    return s1[i] == s2[i];
}

short gethash(Hash** h, char* key)
{
    unsigned int index = hash(key);
    for (Hash* np = h[index]; np != NULL; np = np ->next)
    {
        if (strmatch(np->key, key)) return np->type;
    }

    return -1;
}

short getmap(Map* m, char* key)
{
    return gethash(m->hash, key);
}

void release_hash(Hash** root)
{
    for (unsigned int i = 0; i < HASHSIZE; i++)
    {
        Hash *current = root[i],  *next;
        for (; current != NULL; current = next)
        {
            next = current->next;
            free(current->key);
            free(current);
        }
    }

    free(root);
    return;

} 
