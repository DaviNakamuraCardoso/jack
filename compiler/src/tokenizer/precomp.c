/**
*       Performs the precompilation, skipping whitespaces and comments
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tokenizer/tokens.h>
#include <tokenizer/precomp.h>
#include <tokenizer/reader.h>
#include <tokenizer/cleaner.h>
#include <utils/error.h>


unsigned int is_whitespace(char* ptr)
{
    return (*ptr <= 32 || *ptr == 127);
}

unsigned int is_not_endofline(char* c)
{
    switch (*c)
    {
        case 0:
        case '\n':
        case '\r':
        case '\v':
            return 0;

    }
    return 1;
}

unsigned int is_not_endof_comment(char* c)
{
    return !((c[-1]) == '*' && (c[0]) == '/');
}

char* cycle_text(char* text, unsigned int (*validator) (char*))
{
    char* ptr;

    for (ptr = text; validator(ptr) && (*ptr) != '\0'; ptr++) {}

    return ptr;
}


char* handle_whitespaces(char* text)
{
    if (!is_whitespace(text)) return text;
    return cycle_text(text, is_whitespace);
}

char* handle_inline_comments(char* text)
{
    char* ret;

    if (text[0] != '/' || text[1] != '/') return text;

    // Gets a pointer to the first endofline
    ret = cycle_text(text, is_not_endofline);

    // Avoids empty strings
    ret = (*ret == '\0')? ret : (ret+1);

    return (ret);
}

char* handle_multiple_line_comments(char* text)
{
    char* ret;

    if (text[0] != '/' || text[1] != '*') return text;

    ret = cycle_text(text, is_not_endof_comment);

    ret = (*ret == '\0')? ret : (ret+1);

    return (ret);
}


unsigned int is_code(char current, char next)
{

    switch (current) {
        case '/':
        {
            switch (next) {
                case '*':
                case '/':
                {
                    return 0;
                }
                default:
                {
                    return 1;
                }
            }
        }
        case ' ':
        case '\n':
        case '\r':
        case '"':
        case '\0':
        {
            return 0;
        }
    }

    return 1;
}

char* next_code(char* source)
{
    char* clean = handle_whitespaces(handle_inline_comments(handle_multiple_line_comments(source)));
    clean = handle_inline_comments(handle_whitespaces(handle_multiple_line_comments(clean)));
    clean = handle_whitespaces(handle_multiple_line_comments(handle_inline_comments(clean)));
    clean = handle_inline_comments(handle_multiple_line_comments(handle_whitespaces(clean)));
    return handle_multiple_line_comments(handle_inline_comments(handle_whitespaces(clean)));
}

char* get_string_literals(char* source, FILE* f)
{
    int i;
    if (source[0] != '"') return source;

    if (strchr(++source, '"') == NULL) error("Unmatched \" in string declaration\n");

    fputc('"', f);
    for (i = 0; source[i] != '"'; i++)
    {
        fputc(source[i], f);
    }
    fputc('"', f);
    fputc('\n', f);

    return source+i+1;
}


char* get_code(char* current, FILE* f)
{
    short s;
    for (s = 0; is_code(current[s], current[s+1]); s++)
    {
        fputc(current[s], f);
    }
    if (s > 0) fputc('\n', f);

    return current+s;
}


char* clean_source(char* source)
{

    char* current;
    FILE* f;

    current = source;

    f = fopen("tokens.out", "w");
    while (current[0] != '\0')
    {
        current = next_code(current);
        current = get_string_literals(current, f);
        current = get_code(current, f);
    }
    fclose(f);

    return get_file("tokens.out");

}


char* precompile(char* filename)
{
    short s;
    char *source, *cleaned, *precompiled;

    source = get_file(filename);

    // Removes all comments and whitespaces
    cleaned = clean_source(source);

    // Split all tokens
    precompiled = split_symbols(cleaned);

    free(source);
    free(cleaned);

    return precompiled;

}
