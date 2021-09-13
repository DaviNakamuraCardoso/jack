
#include <tokenizer/tokens.h>
#include <table/table.h>
#include <writer/tracker.h>

typedef struct _code {
    int* identation;
    FILE* source;
    FILE* target;
    FILE* vm;
    TABLE* table;
    TRACKER* tracker;
} CODE;

// Print the tag to a file using the current identation
void compilef(int identation, char* text, FILE* target);

// Increase the current identation by 1
void inc(int* identation);

// Decrease the current identation by 1
void dec(int* identation);


/**
*   Manipulating the tracker
*/
unsigned long get_counter(CODE* c);
unsigned long see_counter(CODE* c); 

/**
*       Handling implemented elements
*/
unsigned int compile_symbol(CODE* c, char* symbol);
unsigned int compile_keyword(CODE* c, char* keyword);

unsigned int compile_identifier(CODE* c);


/**
*       Terms
*/
unsigned int compile_const(CODE* c, char* keyword);
unsigned int compile_varname(CODE* c);
unsigned int compile_stringconstant(CODE* c);
unsigned int compile_integerconstant(CODE* c);


/**
*       Assertions
*/
void assert_type(TOKEN_TYPE a, TOKEN_TYPE b, int* status);
void assert_content(char* a, char* b, int* status);


/**
*   Useful XML functions
*/
void opentag(CODE* c, const char* tagname);
void closetag(CODE* c, const char* tagname);

short is_next(CODE* c, char* content, TOKEN_TYPE type);

void get_next_token_content(CODE* c, char* buffer);


CODE* new_code(FILE* source, FILE* target, FILE* vm);
void release_code(CODE* c);
