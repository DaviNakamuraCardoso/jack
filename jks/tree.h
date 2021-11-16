#ifndef __TREEH
#define __TREEH

typedef struct tree tree_t;

tree_t* tree_new(void);
tree_t* tree_add(tree_t *t, char* symbol);
char tree_next(tree_t *t, char* current); 
void tree_destroy(tree_t* t); 

#endif
