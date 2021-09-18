/*** Cleaner */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <tokenizer/reader.h>
#include <tokenizer/tokens.h>
#include <tokenizer/cleaner.h>
#include <utils/error.h>



unsigned long long escape_string_literals(char* source, FILE* f)
{
    unsigned long long l = 0;

    if (source[l] == '"')
    {
        do {
            fputc(source[l], f);
        } while (source[++l] != '"');

        fputc('"', f);

    }


    return l;
}

unsigned long long split_implemented_symbols(char* source, unsigned long long l, FILE* f, SYMBOL* root)
{
    if (search_one_char(root, source+l))
    {
        if (source[l-1] != '\n') fputc('\n', f);
        fputc(source[l], f);
        if (!search_one_char(root, source+l+1) && source[l+1] != '\n') fputc('\n', f);
        return 1;
    }

    return 0;
}

char* split_symbols(char* source)
{
    // Very big number
    unsigned long long i, symbol, strings;
    FILE* f;
    SYMBOL* symbols;

    symbols = new_symbol();
    add_symbols(symbols);

    f = fopen("tokens.out", "w");
    for (i = 0; source[i] != '\0'; i++)
    {
        // Parse string literals
        strings = escape_string_literals(source+i, f);
        if (strings > 0) { i += strings; continue; }

        // Parse symbols
        symbol = split_implemented_symbols(source, i, f, symbols);
        if (symbol) continue;

        // Parse common code
        fputc(source[i], f);
    }

    release_symbol(&symbols);
    fclose(f);

    return get_file("tokens.out");
}

unsigned int is_valid_number_constant(char* number)
{
    short s;
    long int val;

    for (s = 0; number[s] != '\0'; s++)
    {
        if (!isdigit(number[s])) return 0;
    }

    val = atoi(number);

    //if (val > 33000) error("Number constant above the maximum value");

    return 1;
}

TOKEN_TYPE string_or_constant(char* token)
{

    if ((*token) == '"') return STRING_LITERAL;

    if ((*token) >= '0' && (*token) <= '9')
    {
        if (is_valid_number_constant(token)) return NUMBER_CONSTANT;
    }

    return -1;
}

unsigned int is_valid_variable_char(char c)
{
    return (isalpha(c) || c == '_');
}


TOKEN_TYPE check_variable(char* token)
{
    unsigned int i;

    for (i = 0; token[i] != '\0'; i++)
    {
        if (!is_valid_variable_char(token[i])) return -1;
    }

    return VARIABLE;
}

char* get_special_symbol(char* token)
{
    char* equ;
    switch (*token)
    {
        case '&': {
            equ = "&amp;"; break; }
        case '<': {
            equ = "&lt;"; break;}
        case '>': {
            equ = "&gt;"; break; }
        case '"': {
            equ = "&quot;"; break; }
        default: {
            equ = token; break; }
    }

    return equ;
}
