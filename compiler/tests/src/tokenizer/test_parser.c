/*
    Test the tokenizer parser module
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tokenizer/tokens.h>
#include <tokenizer/reader.h>
#include <tokenizer/cleaner.h>
#include <tokenizer/parser.h>

unsigned int test_types_table(void)
{
    unsigned short s, size;
    SYMBOL* types_table;

    char* compare[] = {
        "while",
        "if",
        "&",
        "{",
        "d",
        "i"
    };

    TOKEN_TYPE types[] = {
        KEYWORD, KEYWORD, IMPLEMENTED_SYMBOL, IMPLEMENTED_SYMBOL, -1, -1
    };

    size = 6;

    types_table = new_types_table();

    for (s = 0; s < size; s++)
    {
        if (get_token_type(types_table, compare[s]) != types[s])
        {
            printf("Error in types_table, comparison %i\n", s);
            printf("Result: %i\n", get_token_type(types_table, compare[s]));
            printf("Expected: %i\n", types[s]);
            release_symbol(&types_table);
            return 0;
        }
    }

    release_symbol(&types_table);
    return 1;
}

unsigned int test_get_type(void)
{
    unsigned short s, size;

    char* tokens[] = { "while", "if", "else", "&", "-", "*", "variable",
    "game", "game_mode", "\"Hello, World\"", "\"Hi\"", "\"Tetris\"","929", "10", "29" };

    TOKEN_TYPE types[] = {
        KEYWORD, KEYWORD, KEYWORD,
        IMPLEMENTED_SYMBOL, IMPLEMENTED_SYMBOL, IMPLEMENTED_SYMBOL,
        VARIABLE, VARIABLE, VARIABLE,
        STRING_LITERAL, STRING_LITERAL, STRING_LITERAL,
        NUMBER_CONSTANT, NUMBER_CONSTANT, NUMBER_CONSTANT

    };

    SYMBOL* root;

    root = new_types_table();

    size = 15;

    for (s = 0; s < size; s++)
    {
        if (get_type(root, tokens[s]) != types[s])
        {
            printf("Error in get_type function, test %i\n", s);
            printf("Result: %i\n", get_type(root, tokens[s]));
            printf("Expected: %i\n", types[s]);
            release_symbol(&root);
            return 0;
        }
    }

    release_symbol(&root);

    return 1;
}

unsigned int test_get_tag(void)
{
    unsigned short s, size;
    char* result;

    TOKEN_TYPE input[] = {
        STRING_LITERAL,
        NUMBER_CONSTANT,
        VARIABLE,
        KEYWORD,
        IMPLEMENTED_SYMBOL
    };

    char* tags[] = {
        "stringConstant",
        "integerConstant",
        "identifier",
        "keyword",
        "symbol"
    };

    size = 5;
    for (s = 0; s < size; s++)
    {
        result = get_tagname(input[s]);

        if (strcmp(result, tags[s]) != 0)
        {
            printf("Error in get_tag number %i\n", s);
            printf("Result: %s\n", result);
            printf("Expected: %s\n", tags[s]);
            free(result);

            return 0;
        }

        free(result);

    }

    return 1;
}

unsigned int test_get_xml(void)
{
    short s, size;

    size = 2;
    char* input[] = {
        "class\nMain\n{\nfunction\nvoid\nmain\n(\n)\n{\n}\n}\n",
        "class\nHello\n{\nfunction\nvoid\nhello\n(\n)\n{\nOutput\n.\nprintString\n(\n\"Hello!\"\n)\n}\n}\n"
    };

    for (s = 0; s < size; s++)
    {
        // printf("%s\n", get_xml(input[s]));
    }

    return 1;
}

unsigned int test_tokenize(void)
{
    unsigned short s, size;
    char filename[200], target[200], *result, *expected;


    size = 3;
    for (s = 0; s < size; s++)
    {
        sprintf(filename, "files/tokenizer/tokenize_%i.jack", s);
        sprintf(target, "files/tokenizer/tokenize_%i.xml", s);

        result = tokenize(filename);
        expected = get_file(target);

        if (strcmp(result, expected) != 0)
        {
            printf("Error in tokenize function comparison %i\n", s);
            printf("Result: %s\n", result);
            printf("Expected: %s\n", expected);
            printf("Diff is %i\n", strcmp(result, expected));

            free(expected);
            free(result);
            return 0;
        }

        free(expected);
        free(result);

    }

    return 1;
}

unsigned int test_parser(void)
{
    int i, size;

    unsigned int (*tests[]) (void) = {
        test_types_table,
        test_get_type,
        test_get_tag,
        test_get_xml,
        test_tokenize
    };

    size = 5;

    for (i = 0; i < size; i++)
    {
        if (!tests[i]())
        {
            printf("Error in test %i\n", i);
            return 0;
        }
    }
    return 1;
}
