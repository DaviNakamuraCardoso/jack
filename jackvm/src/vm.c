#include <stdio.h>
#include <stdlib.h>
#include <tokens.h>
#include <cmds/push.h>
#include <cmds/pop.h>
#include <cmds/operators.h>
#include <cmds/jumps.h>


static Program* new_program(Source *s);
void (*commands[]) (Program*) = {
    [PUSH]      = push,
    [POP]       = pop, 
    [LABEL]     = label,
    [GOTO]      = gotoc,
    [IFGOTO]    = ifgoto,
    [CALL]      = call,
    [FUNCTION]  = function,
    [RETURN]    = returnc,
    [ADD]       = add,
    [SUB]       = sub,
    [MULT]      = mult,
    [DIV]       = divc,
    [GT]        = gt,
    [LT]        = lt,
    [EQ]        = eq, 
    [NOT]       = not

};

static char* cmds[] = {
    [PUSH]      = "push",
    [POP]       = "pop",
    [LABEL]     = "label", 
    [GOTO]      = "goto",
    [IFGOTO]    = "if-goto",
    [CALL]      = "call",
    [FUNCTION]  = "function",
    [RETURN]    = "return",
    [ADD]       = "add",
    [SUB]       = "sub",
    [MULT]      = "mult",
    [DIV]       = "div",
    [GT]        = "gt",
    [LT]        = "lt",
    [EQ]        = "eq", 
    [NOT]       = "not"
};


unsigned short next(Program* p)
{
    return p->source[p->pc++];
}

void printstack(Program* p, int n)
{
    puts("====");
    for (int i = 0; i < n; i++)
    {
        printf("%li\n", p->stack[i]);
    }
    puts("====");
}



int vm(Source* s)
{
    Program *p = new_program(s);

    unsigned short zeros = next(p);

    for (int i = 0; i < zeros; i++)
    {
        pushv(p, 0);
    }

    while (!p->done)
    {
        unsigned short c = next(p); 
//        printf(cmds[c]);
        commands[c](p); 
 //       printf("\n");
//        printstack(p, 20);
    }
   
    

    return popv(p);
}

static Program* new_program(Source* s)
{
    Program *p = malloc(sizeof(Program));
    p->source = lcontents(s->tokens);
    p->pc = s->labels[getmap(s->indexes, "Main.main")]; 
    p->sp = 0;
    p->stack = calloc(sizeof(long), 10000);
    p->statics = calloc(sizeof(long), 1000);
    p->tmp = calloc(sizeof(long), 100);
    p->arguments = 0;
    p->locals = 0;
    p->this = 0;
    p->that = 0;
    p->labels = s->labels;
    p->stdcount = s->stdcount;
    p->done = 0;

    
    return p;
    
}
