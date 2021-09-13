#include <stdio.h>
#include <stdlib.h>
#include <tokens.h>


static Hash** cmdhash(void);
static Hash** mseghash(void);

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

static char* memsegs[] = {
    [CONSTANT]  = "constant", 
    [STATIC]    = "static",
    [ARGUMENT]  = "argument",
    [LOCAL]     = "local",
    [THIS]      = "this",
    [THAT]      = "that",
    [POINTER]   = "pointer",
    [TEMP]      = "temp"
};


Source* new_source(void)
{
    Source* s = malloc(sizeof(Source));
    s->tokens = new_list();
    s->cmds= cmdhash();
    s->memsegs = mseghash();
    s->indexes = new_map();
    s->labels = calloc(sizeof(unsigned long), 5000); 
    s->staticcount = 0;

    return s;
}

void release_source(Source* s)
{
    release_hash(s->cmds);
    release_hash(s->memsegs);
    free(s->labels);
    free(s);
}


static Hash** cmdhash(void)
{
    Hash** h = new_hash();
    for (unsigned int i = 0; i < sizeof(cmds) / sizeof(char*); i++)
    {
       add_hash(h, cmds[i], i); 
    }

    return h;
} 


static Hash** mseghash(void)
{
    Hash** h = new_hash();
    for (unsigned int i = 0; i < sizeof(memsegs) / sizeof(char*); i++)
    {
       add_hash(h, memsegs[i], i); 
    }

    return h;
}

