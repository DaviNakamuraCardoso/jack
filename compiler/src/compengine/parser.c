/*
*
*       XML Parser source code for the Davi Compiler Collection (DCC)
*       (c) 2021 Davi Nakamura Cardoso
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tokenizer/tokens.h>
#include <compengine/parser.h>

TOKEN* new_token(char* content, TOKEN_TYPE type)
{
    TOKEN* token;

    token = malloc(sizeof(TOKEN));

    token->type = type;
    token->content = strdup(content);

    return token;
}

TOKEN_TYPE get_token_type_from_tag(char* tagname)
{
    switch (tagname[0]) {
        case 's':
            switch (tagname[1]) {
                case 'y': return IMPLEMENTED_SYMBOL;
                case 't': return STRING_LITERAL;
                default: return INVALID;
            }
        case 'k':
            return KEYWORD;
        case 'i':
            switch (tagname[1]) {
                case 'd':
                    return VARIABLE;
                case 'n':
                    return NUMBER_CONSTANT;
            }
        default: return INVALID;
    }

    return INVALID;
}


TOKEN* parse_token(char* xml)
{
    char *content, *last, *buffer;
    TOKEN_TYPE type;
    TOKEN* t;

    type = get_token_type_from_tag(xml+1);


    buffer = strdup(xml);
    content = strchr(buffer, '>') + 1;

    if (content == NULL) return NULL;

    last = strchr(content, '<');

    if (last == NULL) return NULL;
    *last = '\0';


    /*
                 content
        buffer/
        |    |
        v    v
        <tag>example</tag>
         ^          ^
         |          |
         buffer+1   \
        (xml+1)    last
    */

    t = new_token(content, type);

    *last = '<';
    free(buffer);

    return t;

}

TOKEN* get_next_token(FILE* xml)
{
    char* buff = NULL;
    size_t size, len;
    TOKEN* token;

    len = getline(&buff, &size, xml);

    // Returns NULL if the EOF is reached
    if (len == -1)
    {
        /*  "The user should free the buffer even if the
        *   allocation wasn't successfull" (see 'man getline')
        */
        free(buff);
        return NULL;
    }

    buff[len] = '\0';

    // Get the token
    token = parse_token(buff);
    free(buff);

    return token;
}

void rollback(FILE* f)
{
    char c;
    int p;

    // Skips the first newline character
    fseek(f, -1, SEEK_CUR);

    do {
        fseek(f, -2, SEEK_CUR);

        // Current character
        c = fgetc(f);

        // Position
        p = ftell(f);

    } while (c != '\n' && p > 1);

    // In case of the first element, completely resets the file pointer
    if (p <= 1) rewind(f);

    return;
}


void release_token(TOKEN** tokenptr)
{
    free((*tokenptr)->content);
    free(*tokenptr);
    *tokenptr = NULL;
    return;
}
