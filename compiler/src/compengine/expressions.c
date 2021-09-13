/*
*
*       Set of functions for compiling various expressions
*       (c) 2021 Davi Nakamura Cardoso
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <compengine/compile.h>
#include <compengine/parser.h>
#include <compengine/expressions.h>
#include <compengine/structure.h>
#include <writer/writer.h>
#include <writer/assignments.h>
#include <writer/functions.h>


/*
*   Private functions
*/
void open_expression(CODE* c);
void close_expression(CODE* c);
unsigned int compile_termlist(CODE* c);
signed int compile_unaryop(CODE* c);
signed int compile_op(CODE* c);


static int compile_keylist(CODE* c, char* keylist[], unsigned int (*handler) (CODE*, char*))
{
    int i;
    TOKEN* token;
    unsigned int status = 0;

    token = get_next_token(c->source);

    if (token == NULL) return status;

    rollback(c->source);

    for (i = 1; keylist[i] != NULL; i++)
    {
        if (strcmp(keylist[i], token->content) == 0)
        {
            handler(c, keylist[i]);
            status = i;
            break;
        }
    }
    release_token(&token);
    return status;
}

void compile_expression(CODE* c)
{
    /**
    *   <expression> ::= <term> (<op> <term>)*
    */

    OPERATOR operators[100] = {0};
    int sp = 0;
    opentag(c, "expression");

    do {
        compile_term(c);
    } while ((operators[sp++] = compile_op(c)) != 0);

    write_op(c, operators, --sp);

    closetag(c, "expression");
    return;
}



unsigned int compile_inbraces(CODE* c)
{
    if (is_next(c, "(", IMPLEMENTED_SYMBOL) != 1) return 0;

    compile_symbol(c, "(");

    compile_expression(c);

    compile_symbol(c, ")");

    return 1;
}

unsigned int compile_expressionlist(CODE* c)
{
    /**
    *       <expressionlist> ::= (<expression> (, <expression>)*)?
    */

    int i = 0;

    opentag(c, "expressionList");

    if (is_next(c, ")", IMPLEMENTED_SYMBOL) == 0)
    {
        do {
            compile_expression(c);
            i++;
        } while (compile_comma(c));

    }

    closetag(c, "expressionList");

    return i;
}


unsigned int compile_term(CODE* c)
{
    UNARYOP u = compile_unaryop(c);
    opentag(c, "term");
    compile_termlist(c);

    write_unaryop(c, u);
    closetag(c, "term");
}


unsigned int compile_keywordconstant(CODE* c)
{
    char* list[] = {NULL, "true", "false", "this", "null", NULL };

    return compile_keylist(c, list, compile_const) != 0;
}


signed int compile_unaryop(CODE* c)
{
    char* list[] = {NULL, "~", "-", NULL};
    return compile_keylist(c, list, compile_symbol);
}

signed int compile_op(CODE* c)
{

    char* list[] = {NULL, "+", "-", "*", "/", "&amp;", "|", "&lt;", "&gt;", "=", NULL};
    return compile_keylist(c, list, compile_symbol);
}

static unsigned int check_subroutine(CODE* c, short* is_class, short* is_function)
{
    unsigned int status = 1;
    TOKEN* t = NULL;

    t = get_next_token(c->source);

    *is_class = is_next(c, ".", IMPLEMENTED_SYMBOL);
    *is_function = is_next(c, "(", IMPLEMENTED_SYMBOL);

    if (t == NULL) return 0;

    rollback(c->source);

    assert_type(t->type, VARIABLE, &status);
    release_token(&t);

    if (!status)
    {
        return 0;
    }

    if ((*is_class) != 1 && (*is_function) != 1)
    {
        return 0;
    }

    return 1;

}

unsigned int compile_subroutinecall(CODE* c)
{
    short is_class = 0, is_function = 0, nargs = 0;
    char classname[300], fname[300];

    if (!check_subroutine(c, &is_class, &is_function))
    {
        return 0;
    }

    opentag(c, "subroutineCall");

    if (is_class)
    {

        nargs += push_methodarg(c, classname);
        compile_identifier(c);
        compile_symbol(c, ".");
    }
    else
    {
        write_push_pointer(c, 0);
    }


    get_next_token_content(c, fname);

    compile_identifier(c);

    compile_symbol(c, "(");

    nargs += compile_expressionlist(c);

    compile_symbol(c, ")");

    if (!is_class)
    {
        write_privatecall(c, fname, nargs);
    }
    else
    {
        write_functioncall(c, classname, fname, nargs);
    }

    closetag(c, "subroutineCall");

    return 1;
}

static unsigned int check_arrayaccess(CODE* c)
{
    short status;
    TOKEN* t = NULL;

    t = get_next_token(c->source);

    status = is_next(c, "[", IMPLEMENTED_SYMBOL);

    if (t == NULL) return 0;

    release_token(&t);
    rollback(c->source);

    if (status != 1)
    {
        return 0;
    }

    return 1;
}

unsigned int compile_arrayaccess(CODE* c)
{
    /**
    *       <arrayaccess> ::= <identifier>[<expression>]
    */
    char base_pointer[300];
    if (!check_arrayaccess(c)) return 0;


    get_next_token_content(c, base_pointer);
    write_push(c, base_pointer);
    compile_identifier(c);
    compile_symbol(c, "[");
    compile_expression(c);
    compile_symbol(c, "]");
    write_add(c);
    write_pop_pointer(c, 1);
    write_push_that(c, 0);

    return 1;
}
unsigned int compile_termlist(CODE* c)
{
    unsigned int i;
    unsigned int (*functions[]) (CODE*) = {
        compile_subroutinecall,
        compile_arrayaccess,
        compile_varname,
        compile_integerconstant,
        compile_keywordconstant,
        compile_stringconstant,
        compile_inbraces

    };

    for (i = 0; i < 7; i++)
    {
        if (functions[i](c)) return 1;
    }

    return 0;
}
