#include <stdio.h>
#include <stdlib.h>
#include <pp.h> 
#include <tokenizer.h>

/**
 * include // tokenize
 * define // mtset
 * ifndef // mtget, skip
 * endif // stop
 */

token_t** pinclude(source_t*, token_t**, size_t);
token_t** pdefine (source_t*, token_t**, size_t);
token_t** pifndef (source_t*, token_t**, size_t);
token_t** pendif  (source_t*, token_t**, size_t);

typedef enum {
    INCLUDE, DEFINE, IFNDEF, ENDIF,
    __INSTRUCTION_COUNT, 
} instruction_e;

const char* instructions[] = {
    [INCLUDE] = "include", 
    [DEFINE]  = "define", 
    [IFNDEF]  = "ifndef",
    [ENDIF]   = "endif",
};

_Static_assert (sizeof(instructions) / sizeof(char*) == __INSTRUCTION_COUNT, "Instruction enumeration does not match instruction words.\n");

token_t** (*directives[]) (source_t*, token_t**, size_t) = {
    [INCLUDE] = pinclude,
    [DEFINE]  = pdefine,
    [IFNDEF]  = pifndef,
    [ENDIF]   = pendif, 
};

_Static_assert (sizeof(directives) / sizeof(token_t**(*)(source_t*, token_t**, size_t)) == __INSTRUCTION_COUNT, "Instruction enumeration does not match instruction directives.\n");

instruction_e get_instruction(char* word) 
{ 
    for (size_t i = 0; i < __INSTRUCTION_COUNT; i++)
    {
        if (strcmp(word, instructions[i]) == 0) return i; 
    } 
    return __INSTRUCTION_COUNT;
}


token_t **preprocess(source_t *s, token_t** ts)
{ 
    long i = 0; 
    for (; (long) tkvalue(ts[i]) != HASH; i--);

    char *directive = (char*) tkvalue(ts[i+1]);
    instruction_e d = get_instruction(directive);

    if (d == __INSTRUCTION_COUNT) 
    {
        errorat(s->filename, tkloc(ts[i+1]), "Invalid preprocessing directive '#%s';\n", directive);
        exit(1);
    }

    return directives[d](s, ts, (size_t) -(i+1));
} 


token_t** pinclude(source_t* s, token_t** ts, size_t nargs)
{
    if (nargs != 1)
    {
        errorat(s->filename, tkloc(ts[0]), "extra tokens at end of #include directive");
        exit(1); 
    }
    return ftokenize(ts-nargs-1, (char*) tkvalue(ts[0]), s->t, s->mt);
}

token_t** pdefine(source_t* s, token_t** ts, size_t nargs)
{
    (void)s;
    return ts-nargs-1;
}

token_t** pifndef(source_t* s, token_t** ts, size_t nargs)
{
    (void)s;
    return ts-nargs-1;
}

token_t** pendif(source_t* s, token_t** ts, size_t nargs)
{
    (void)s;
    return ts-nargs-1;
}
