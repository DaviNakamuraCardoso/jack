/*
*
*    A set of generic compile functions used by all compilation engine modules
*    (c) 2021 Davi Nakamura Cardoso
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <compengine/compile.h>
#include <compengine/parser.h>
#include <writer/assignments.h>
#include <utils/error.h>


// Private function putident
void putident(int ident, FILE* f);
void compile_variable(CODE* c, TOKEN* t);
unsigned int compile_value(CODE* c, TOKEN_TYPE type);


void compilef(int identation, char* text, FILE* target)
{
    if (target == NULL) return;

    putident(identation, target);
    fprintf(target, "%s\n", text);
    return;
}


void dec(int *identation)
{
    *identation = *identation - 1;
    return;
}


void inc(int *identation)
{
    *identation = *identation + 1;
    return;
}


void putident(int ident, FILE* f)
{
    for (int i = 0; i < ident; i++) { fputc('\t', f); }
    return;
}

// Get the current value of the counter and modifies it
unsigned long get_counter(CODE* c)
{
    if (c->tracker == NULL) return 0;
    return (c->tracker->counter++);
}

// Get the current value of the counter without modifying it
unsigned long see_counter(CODE* c)
{
    if (c->tracker == NULL) return 0;
    return (c->tracker->counter);
}

void assert_type(TOKEN_TYPE a, TOKEN_TYPE b, int* status)
{
    if (a != b)
    {
        *status = 0;
    }
    return;
}

void assert_content(char* a, char* b, int* status)
{
    if (strcmp(a, b) != 0)
    {
        *status = 0;
    }
    return;
}

void compile_symbol_tag(int *identation, char* content, FILE* target)
{
    char tag[500];

    sprintf(tag, "<symbol>%s</symbol>", content);
    compilef(*identation, tag, target);
    return;
}

void compile_tag(CODE* c, char* content, char* tagname)
{
    char tag[1000];

    sprintf(tag, "<%s> %s </%s>", tagname, content, tagname);
    compilef(*(c->identation), tag, c->target);
    return;

}

unsigned int compile_implemented(CODE* c, char* content, char* tagname, TOKEN_TYPE type)
{
    TOKEN* token = get_next_token(c->source);
    unsigned int status = 1;

    assert_type(token->type, type, &status);
    assert_content(token->content, content, &status);

    if (!status)
    {
        release_token(&token);
        return 0;
    }

    compile_tag(c, content, tagname);
    release_token(&token);

    return 1;

}


unsigned int compile_symbol(CODE* c, char* symbol)
{
    return compile_implemented(c, symbol, "symbol", IMPLEMENTED_SYMBOL);
}

unsigned int compile_keyword(CODE* c, char* keyword)
{
    return compile_implemented(c, keyword, "keyword", KEYWORD);
}

unsigned int compile_const(CODE* c, char* keyword)
{
    return compile_value(c, KEYWORD);
}

unsigned int compile_value(CODE* c, TOKEN_TYPE type)
{
    int status = 1;
    TOKEN* token;


    token = get_next_token(c->source);

    assert_type(token->type, type, &status);

    // "symbol", "keyword", "stringConstant", "integerConstant", "identifier"

    void (*writers[]) (CODE*, char*) = {
        NULL,
        write_keyconstant,
        write_stringliteral,
        write_intconstant,
        write_push

    };

    if (status)
    {
        if (writers[token->type] != NULL) writers[token->type](c, token->content);
        compile_variable(c, token);
    }
    else
    {
        rollback(c->source);
    }

    release_token(&token);
    return status;
}


unsigned int compile_identifier(CODE* c)
{
    int status = 1;
    TOKEN* token;
    TOKEN_TYPE type = VARIABLE;
    token = get_next_token(c->source);

    assert_type(token->type, type, &status);

    // "symbol", "keyword", "stringConstant", "integerConstant", "identifier"
    if (status)
    {
        compile_variable(c, token);
    }
    else
    {
        rollback(c->source);
    }
    release_token(&token);
    return status;
}

unsigned int compile_varname(CODE* c)
{
    return compile_value(c, VARIABLE);
}


unsigned int compile_stringconstant(CODE* c)
{
    return compile_value(c, STRING_LITERAL);
}


unsigned int compile_integerconstant(CODE* c)
{
    return compile_value(c, NUMBER_CONSTANT);
}

void compile_string(CODE* c)
{
    TOKEN* token = get_next_token(c->source);

}

void compile_variable(CODE* c, TOKEN* t)
{
    char tag[500];

    char* tagnames[] = {
        "symbol", "keyword", "stringConstant", "integerConstant", "identifier"
    };

    sprintf(tag, "<%s> %s </%s>", tagnames[t->type], t->content, tagnames[t->type]);
    compilef(*(c->identation), tag, c->target);

    return;
}

void opentag(CODE* c, const char* tagname)
{
    char tag[500];
    sprintf(tag, "<%s>", tagname);

    compilef(*(c->identation), tag, c->target);

    inc(c->identation);

    return;
}

void closetag(CODE* c, const char* tagname)
{
    char tag[500];
    sprintf(tag, "</%s>", tagname);

    dec(c->identation);

    compilef(*(c->identation), tag, c->target);

    return;
}




short is_next(CODE* c, char* content, TOKEN_TYPE type)
{
    unsigned int status = 1;
    TOKEN* next = NULL;

    next = get_next_token(c->source);

    if (next == NULL)
    {
        return -1;
    }

    rollback(c->source);

    assert_type(type, next->type, &status);
    assert_content(content, next->content, &status);

    release_token(&next);

    return status;

}


/**
 *
 * @param c -> source code being analyzed
 * @return r -> content of the next token (the caller must free the value)
 */
void get_next_token_content(CODE* c, char* buffer)
{
    TOKEN* t;

    t = get_next_token(c->source);
    rollback(c->source);

    buffer[0] = '\0';

    if (t == NULL) return;
    if (t->content == NULL) return;

    strncpy(buffer, t->content, 300);

    release_token(&t);

    return;
}

static CODE* codealloc(void)
{
    return (CODE*) malloc(sizeof(CODE));
}

static int* intalloc(void)
{
    int* r = (int*) malloc(sizeof(int));
    *r = 0;
    return r;
}

CODE* new_code(FILE* source, FILE* target, FILE* vm)
{
    CODE* c = codealloc();

    c->source = source;
    c->target = target;
    c->vm = vm;
    c->identation = intalloc();
    c->table = NULL;
    c->tracker = NULL;

    return c;
}
void release_code(CODE* c)
{

    if (c->source != NULL) fclose(c->source);
    if (c->target != NULL) fclose(c->target);
    if (c->vm != NULL)     fclose(c->vm);
    if (c->table != NULL)  release_table(&(c->table));
    if (c->identation != NULL) free(c->identation);


    free(c);
}
