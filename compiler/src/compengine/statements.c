/*
*       Compile statements for the Davi Compiler Collection (DCC)
*       (c) 2021 Davi Nakamura Cardoso
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <compengine/compile.h>
#include <compengine/parser.h>
#include <compengine/expressions.h>
#include <compengine/statements.h>
#include <compengine/structure.h>
#include <writer/writer.h>
#include <writer/assignments.h>
#include <writer/loops.h>

// Private functions
void open_statement(int* identation, char* keyword, FILE* target);
void close_statement(int* identation, char* keyword, FILE* target);

void open_statements(CODE* c);
unsigned int handle_statements(CODE* c, STATEMENT type);
void close_statements(CODE* c);
STATEMENT get_statement(TOKEN* t);

void compile_statements(CODE* c)
{
    /*
    *   <statements>    ::= <statement>*
    *   <statement>     ::= <let> | <if> | <while> | <do> | <return>
    */

    TOKEN* next;
    STATEMENT type;

    open_statements(c);
    do {
        next = get_next_token(c->source);

        if (next == NULL) break;
        type = get_statement(next);
        rollback(c->source);
        release_token(&next);

    } while (handle_statements(c, type));
    close_statements(c);

    return;

}

void compile_else(CODE* c)
{

    /*
    *   <else> ::= else { <statements> }
    */

    char content[300];

    get_next_token_content(c, content);

    if (strcmp(content, "else") != 0) return;

    compile_keyword(c, "else");

    compile_symbol(c, "{");

    compile_statements(c);

    compile_symbol(c, "}");


    return;
}

void compile_if(CODE* c)
{
    char label1[300], label2[300];

    open_statement(c->identation, "if", c->target);

    // Get the next two label names
    get_label(c, label1);
    get_label(c, label2);


    compile_keyword(c, "if");

    compile_symbol(c, "(");

    compile_expression(c);

    compile_symbol(c, ")");

    // Denies the expression
    write_not(c);
    write_ifgoto(c, label1);

    compile_symbol(c, "{");

    compile_statements(c);

    compile_symbol(c, "}");

    write_goto(c, label2);

    write_label(c, label1);

    compile_else(c);

    write_label(c, label2);

    close_statement(c->identation, "if", c->target);

    return;
}

void compile_while(CODE* c)
{
    /***
        <whileStatement> ::= while ( <expression> ) { <statements> }
    */
    char label1[300], label2[300];

    // Get the two next labels
    get_label(c, label1);
    get_label(c, label2);

    open_statement(c->identation, "while", c->target);  // '<whileStatement>'

    write_label(c, label1);

    compile_keyword(c, "while");

    compile_symbol(c, "(");        // (

    compile_expression(c);          // <expression>

    compile_symbol(c, ")");       // )

    // Denies the expression
    write_not(c);

    write_ifgoto(c, label2);

    compile_symbol(c, "{");

    compile_statements(c);          // <statements>

    compile_symbol(c, "}");

    write_goto(c, label1);

    write_label(c, label2);

    close_statement(c->identation, "while", c->target); // '</whileStatement>'

    return;
}

void compile_return(CODE* c)
{
    /**
    *   <return> ::= return <expression>? ;
    */

    TOKEN* next;

    open_statement(c->identation, "return", c->target);
    compile_keyword(c, "return");

    next = get_next_token(c->source);
    rollback(c->source);

    if (strcmp(next->content, ";") != 0)
    {
        compile_expression(c);
    }
    else
    {
        write_push_constant(c, 0);
    }

    compile_symbol(c, ";");
    close_statement(c->identation, "return", c->target);

    writevm(c, "return");

    release_token(&next);
    return;

}

static unsigned int compile_access(CODE* c)
{
    if (is_next(c, "[", IMPLEMENTED_SYMBOL) != 1) return 0;

    compile_symbol(c, "[");
    compile_expression(c);
    compile_symbol(c, "]");

    return 1;

}

void compile_let(CODE* c)
{
    /**
    *       <let> ::= let <identifier> = <expressions> ;
    */
    char var[300];
    unsigned int is_array_access;
    open_statement(c->identation, "let", c->target);
    compile_keyword(c, "let");

    // Check for an identifier

    get_next_token_content(c, var);


    compile_identifier(c);

    is_array_access = compile_access(c);
    if (is_array_access)
    {
        write_push(c, var);
        //write_add(c);
    }


    compile_symbol(c, "=");

    compile_expression(c);

    compile_symbol(c, ";");

    if (is_array_access)
    {
        write_pop_temp(c, 0);
        write_pop_pointer(c, 1);
        write_push_temp(c, 0);
        write_pop_that(c, 0);
    }
    else
    {
        write_pop(c, var);
    }

    close_statement(c->identation, "let", c->target);

    return;
}

static void dump_return(CODE* c)
{
    write_pop_temp(c, 0);
}

void compile_do(CODE* c)
{

    /**
    *       <do> ::= do <subroutinecall> ;
    */
    open_statement(c->identation, "do", c->target);

    compile_keyword(c, "do");

    compile_subroutinecall(c);

    compile_symbol(c, ";");

    dump_return(c);

    close_statement(c->identation, "do", c->target);

    return;

}


void open_statement(int* identation, char* keyword, FILE* target)
{
    char tag[500];
    sprintf(tag, "<%sStatement>", keyword);

    compilef(*identation, tag, target);

    inc(identation);

    return;
}

void close_statement(int* identation, char* keyword, FILE* target)
{
    char tag[500];
    sprintf(tag, "</%sStatement>", keyword);
    dec(identation);
    compilef(*identation, tag, target);

    return;

}

void open_statements(CODE* c)
{
    compilef(*(c->identation), "<statements>", c->target);
    inc(c->identation);
    return;
}

void pass(CODE* c) {return;}

unsigned int handle_statements(CODE* c, STATEMENT type)
{
    if (type == INVALID_STATEMENT) return 0;

    void (*handlers[]) (CODE*) = {
        pass,
        compile_let,
        compile_if,
        compile_while,
        compile_do,
        compile_return
    };

    handlers[type](c);

    return 1;
}

void close_statements(CODE* c)
{
    dec(c->identation);
    compilef(*(c->identation), "</statements>", c->target);
    return;
}

STATEMENT get_statement(TOKEN* t)
{
    if (t->type != KEYWORD) return INVALID_STATEMENT;

    switch (t->content[0]) {
        case 'w': return WHILE;
        case 'i': return IF;
        case 'd': return DO;
        case 'l': return LET;
        case 'r': return RETURN;
    }

    return INVALID_STATEMENT;
}
