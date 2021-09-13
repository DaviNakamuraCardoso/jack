/**
*
*           Symbol table for the Davi Compiler Collection
*           (c) 2021 Davi Nakamura Cardoso
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <table/table.h>


static TABLE* talloc(void)
{

    return (TABLE*) malloc(sizeof(TABLE));
}

static __VARIABLE* varalloc(void)
{
    return (__VARIABLE*) malloc(sizeof(__VARIABLE));
}

TABLE* new_table(char* classname)
{
    TABLE* t = talloc();

    t->variables = calloc(sizeof(__VARIABLE*), HASHSIZE);

    for (int i = 0; i < HASHSIZE; i++)
    {
        t->variables[i] = NULL;
    }

    t->classname = classname;
    t->next = NULL;

    for (int j = 0; j < 4; j++)
    {
        t->kind_counter[j] = 0;
    }


    return t;
}

static void add_classname(__VARIABLE* v, char* classname, TYPE t)
{
    if (is_primitive(t) || classname == NULL)
    {
        v->classname = NULL;
    }
    else
    {
        v->classname = strdup(classname);
    }
    return;
}

__VARIABLE* new_variable(char* name, char* classname, KIND k, TYPE t)
{
    __VARIABLE* v = varalloc();
    v->name = strdup(name);
    v->kind = k;
    v->type = t;
    v->index = 0;
    v->next = NULL;
    add_classname(v, classname, t);

    return v;
}


void release_variable(__VARIABLE* v)
{

    __VARIABLE* current, *next;

    if (v == NULL) return;

    for (current = v; current != NULL; current = next)
    {
        next = current->next;
        free(current->name);
        if (current->classname != NULL) free(current->classname);
        free(current);
    }

    return;
}


/**
 *
 * @param t->table
 */
void release_table(TABLE** t)
{
    if (*t == NULL) return;

    release_table(&(*t)->next);

    for (int i = 0; i < HASHSIZE; i++)
    {
        release_variable((*t)->variables[i]);
    }

    free((*t)->variables);
    free(*t);

    *t = NULL;

    return;
}

unsigned int get_object_size(TABLE* root)
{
    TABLE* head = root;
    while (head->next != NULL) head = head->next;
    return head->kind_counter[FIELD];
}

void add_hash(TABLE* root, __VARIABLE* variable)
{
    // Prevent segfaults
    if (root == NULL) return;
    if (variable == NULL) return;

    int index = hash(variable->name);
    variable->next = root->variables[index];
    root->variables[index] = variable;

    // Increase the counter for the kind and assign an index for the variable
    variable->index = root->kind_counter[variable->kind]++;

    return;
}

__VARIABLE* search_table(TABLE* root, char* name)
{
    // If the root is NULL, then the variable wasn't declared in any scope
    if (root == NULL) return NULL;

    int index = hash(name);
    __VARIABLE* current, *next;


    for (current = root->variables[index]; current != NULL; current = next)
    {
        next = current->next;
        if (strcmp(name, current->name) == 0)
        {
            return current;
        }
    }

    // Search in the outer scope
    return search_table(root->next, name);
}


void add_var(TABLE* root, char* varname, char* classname, KIND k, TYPE t)
{
    __VARIABLE* v = new_variable(varname, classname, k, t);
    add_hash(root, v);

    return;
}


/**
*   Hash function from K&R,
*   chapter 6.6, page 128
*/
static unsigned int hash(char* s)
{
    unsigned int hash_val;

    for (hash_val = 0; *s != '\0'; s++)
    {
        hash_val = *s + 31 * hash_val;
    }

    return (hash_val % HASHSIZE);
}

static void get_primitive(TYPE t, char* buffer)
{
    char* primitives[] = {
        "int", "char", "boolean"
    };

    strcpy(buffer, primitives[t]);

    return;
}

void get_typename(__VARIABLE* v, char* buffer)
{
    if (is_primitive(v->type))
    {
        get_primitive(v->type, buffer);
        return;
    }

    strncpy(buffer, v->classname, 300);
    return;
}

static unsigned int is_primitive(TYPE t)
{
    switch (t)
    {
        case INT:
        case BOOLEAN:
        case CHAR:
        {
            return 1;
        }
    }

    return 0;
}
