/*** Define the data structures for the tokenizer **/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <tokenizer/tokens.h>
#include <utils/error.h>

const char* keywords[] = {
    "while",
    "if",
    "else",
    "let",
    "do",
    "var",
    "field",
    "class",
    "method",
    "function",
    "constructor",
    "boolean",
    "int",
    "char",
    "this",
    "null",
    "return",
    "true",
    "false",
    "void",
    "static"
};

const char* symbols[] = {
    "{",
    "}",
    "(",
    ")",
    "<",
    ">",
    "[",
    "]",
    "-",
    ".",
    ";",
    ",",
    "+",
    "*",
    "/",
    "&",
    "|",
    "=",
    "~"
};

SYMBOL* new_symbol(void)
{
    unsigned short s;
    SYMBOL* new;

    new = malloc(sizeof(SYMBOL));

    for (s = 0; s < MAX_ASCII; s++)
    {
        new->next[s] = NULL;
    }

    new->exists = 0;
    new->type = -1;

    return new;
}


void release_symbol(SYMBOL** root)
{
    short s;

    if (root == NULL) return;
    if (*root == NULL) return;

    for (s = 0; s < MAX_ASCII; s++)
    {
        release_symbol(&(*root)->next[s]);
    }


    free(*root);
    *root = NULL;
    return;
}


void add_symbol(SYMBOL* root, char* key, TOKEN_TYPE type)
{
    short s, ascii;
    SYMBOL* current;

    if (root == NULL) return;

    current = root;
    for (s = 0; key[s] != '\0'; s++)
    {
        ascii = (int) key[s];
        if (current->next[ascii] == NULL)
        {
            current->next[ascii] = new_symbol();
        }
        current = current->next[ascii];
    }

    current->exists = 1;
    current->type = type;

    return;
}

SYMBOL* get_symbol(SYMBOL* root, char* key)
{
    short s, ascii;
    SYMBOL* current;

    current = root;
    for (s = 0; key[s] != '\0'; s++)
    {
        ascii = (int) key[s];
        if (current->next[ascii] == NULL) return NULL;
        current = current->next[ascii];
    }

    return current;
}


unsigned int search_symbol(SYMBOL* root, char* key)
{
    SYMBOL* s;

    s = get_symbol(root, key);

    if (s == NULL) return 0;
    return (s->exists);
}

TOKEN_TYPE get_token_type(SYMBOL* root, char* key)
{

    SYMBOL* s = get_symbol(root, key);

    if (s == NULL) return -1;

    return s->type;
}


unsigned int search_one_char(SYMBOL* root, char* key)
{
    char character[2];

    character[0] = key[0];
    character[1] = '\0';

    return search_symbol(root, character);
}


void add_symbols_from_table(root, table, tablesize, type)
    SYMBOL* root;
    const char** table; 
    unsigned short tablesize;
    TOKEN_TYPE type;
{
    for (int i = 0; i < tablesize; i++)
    {
        add_symbol(root, table[i], type);
    }

    return;
}

void add_symbols(SYMBOL* root)
{
    add_symbols_from_table(root, symbols, 
            sizeof(symbols) / sizeof(char*), IMPLEMENTED_SYMBOL);
}

void add_syntax(SYMBOL* root)
{
    add_symbols_from_table(root, keywords, 
            sizeof(keywords) / sizeof(char*), KEYWORD);

    add_symbols_from_table(root, symbols, 
            sizeof(symbols) / sizeof(char*), IMPLEMENTED_SYMBOL);
}


