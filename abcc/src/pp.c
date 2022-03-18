#include <stdio.h>
#include <stdlib.h>
#include <pp.h> 

/**
 * include // tokenize
 * define // mtset
 * ifndef // mtget, skip
 * endif // stop
 */

typedef enum {
    INCLUDE, DEFINE, IFNDEF, ENDIF,
    __INSTRUCTION_COUNT, 
} instruction_e;

const char* instructions[] = {
    [INCLUDE] = "include", 
    [DEFINE] = "define", 
    [IFNDEF] = "ifndef",
    [ENDIF] = "endif",
};

_Static_assert (sizeof(instructions) / sizeof(char*) == __INSTRUCTION_COUNT, "Instruction enumeration does not match instructions.\n");

instruction_e get_instruction(token_t* t) 
{
    char* word = (char*) tkvalue(t);

    for (size_t i = 0; i < __INSTRUCTION_COUNT; i++)
    {
        if (strcmp(word, instructions[i]) == 0) return i; 
    }

    errorat(NULL, tkloc(t), "Invalid macro '%s'\n", word);

    return __INSTRUCTION_COUNT;
}

token_t **preprocess(token_t** tokens)
{
    for (size_t i = 0; tokens[i] != NULL; i++)
    {
        if (tktype(tokens[i]) == SYMBOL) 
        {
            if ((unsigned int) tkvalue(tokens[i]) == HASH)
                puts("Here");
        }

    }
    return tokens;
} 


