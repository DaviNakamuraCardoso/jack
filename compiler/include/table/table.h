/**
*
*       Header files for the table module
*
*/


#ifndef HASHSIZE
#define HASHSIZE 101
#endif

#ifndef __TYPE
#include <table/types.h>
#define __TYPE
#endif

#ifndef __KIND
#include <table/kinds.h>
#define __KIND
#endif

typedef enum {
    METHOD, FUNCTION, CONSTRUCTOR
} __F_TYPE;


typedef struct _variable {
    char* name;
    char* classname;
    KIND kind;
    TYPE type;
    unsigned int index;
    struct _variable* next;

} __VARIABLE;

typedef struct _table {
    __VARIABLE** variables;
    struct _table* next;
    int kind_counter[4];
    char* classname;

} TABLE;

// Constructors
TABLE* new_table(char* classname);
__VARIABLE* new_variable(char* name, char* classname, KIND k, TYPE t);

// Deallocators
void release_table(TABLE** t);
void release_variable(__VARIABLE* v);


// Adds and searches for variables in the symbol table
static unsigned int hash(char* s);
void add_hash(TABLE* root, __VARIABLE* variable);
void add_var(TABLE* root, char* varname, char* classname, KIND k, TYPE t);
__VARIABLE* search_table(TABLE* root, char* name);


// Manipulation
static unsigned int is_primitive(TYPE t);

void get_typename(__VARIABLE* v, char* buffer);
unsigned int get_object_size(TABLE* root); 
