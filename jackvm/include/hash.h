
#ifndef __HASHH
#define __HASHH

typedef struct _hash {
    short type;
    char* key;
    struct _hash* next; 
} Hash; 

typedef struct _map {
    Hash** hash;
    unsigned short counter;
} Map;

Hash** new_hash(void); 
Map* new_map(void);

void add_map(Map* m, char* key);
void add_hash(Hash** h, char* key, short value); 

short gethash(Hash** h, char* key); 
short getmap(Map* m, char* key);
void release_hash(Hash** root); 

#endif 

