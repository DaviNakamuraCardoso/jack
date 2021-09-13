/**
*
*       Tests for the Compilation Engine Parser
*       (c) 2021 Davi Nakamura Cardoso
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tokenizer/tokens.h>
#include <compengine/parser.h>


unsigned int test_new_token(void)
{
    unsigned short s, size;
    TOKEN* token;

    char* contents[] = {
        "",
        "class",
        "&",
        "Hello, World!",
        "3292",
        "camel"
    };

    TOKEN_TYPE types[] = {
        INVALID,
        KEYWORD,
        IMPLEMENTED_SYMBOL,
        STRING_LITERAL,
        NUMBER_CONSTANT,
        VARIABLE

    };

    size = 6;

    for (s = 0; s < size; s++)
    {
        token = new_token(contents[s], types[s]);

        if (token == NULL)
        {
            printf("Fail in new_token test %i\n", s);
            printf("New struct is NULL.\n");
            return 0;
        }

        if (token->type != types[s])
        {
            printf("Fail in new_token test %i\n", s);
            printf("Wrong TOKEN_TYPE assigned to new element.\n");
            return 0;
        }

        if (strcmp(token->content, contents[s]) != 0)
        {
            printf("Fail in new_token test %i\n", s);
            printf("Wrong content assigned to new element.\n");
            return 0;
        }

        release_token(&token);
    }
    return 1;
}

unsigned int test_release_token_compengine(void)
{
    unsigned short s, size;
    TOKEN* tokens[500];

    size = 500;

    for (s = 0; s < size; s++)
    {
        tokens[s] = new_token("Hello", STRING_LITERAL);
    }

    for (s = 0; s < size; s++)
    {
        release_token(&tokens[s]);
    }

    return 1;

}

unsigned int test_parse_token_compengine(void)
{
    unsigned short s, size;
    TOKEN* token;

    char* tags[] = {
        "<symbol>(</symbol>",
        "<keyword>my</keyword>",
        "<stringConstant>Hello, World</stringConstant>",
        "<identifier>hello</identifier>",
        "<integerConstant>39</integerConstant>"
    };

    char* contents[] = {
        "(",
        "my",
        "Hello, World",
        "hello",
        "39"
    };

    TOKEN_TYPE types[] = {
        IMPLEMENTED_SYMBOL,
        KEYWORD,
        STRING_LITERAL,
        VARIABLE,
        NUMBER_CONSTANT
    };

    size = 5;

    for (s = 0; s < size; s++)
    {
        token = parse_token(tags[s]);

        if (token->type != types[s])
        {
            printf("Wrong type\n");
            return 0;
        }

        if (strcmp(token->content, contents[s]) != 0)
        {
            printf("Wrong content.\n");
            printf("Result: %s\n", token->content);
            printf("Expected: %s\n", contents[s]);
            return 0;
        }

        release_token(&token);
    }
}

unsigned int test_get_next_token(void)
{
    unsigned short s, t, size;
    FILE* f;

    TOKEN* result;

    TOKEN tokens[] = {
        {.content="class", .type=KEYWORD},
        {.content="Hello", .type=VARIABLE},
        {.content="Howdy, World!", .type=STRING_LITERAL},
        {.content="29", .type=NUMBER_CONSTANT},
        {.content="~", .type=IMPLEMENTED_SYMBOL}
    };

    size = 5;

    f = fopen("./files/compengine/get_next_token.xml", "r");
    for (s = 0; s < size; s++)
    {
        result = get_next_token(f);

        if (result->type != tokens[s].type)
        {
            printf("Wrong token type.\n");
            return 0;
        }

        if (strcmp(result->content, tokens[s].content) != 0)
        {
            release_token(&result);
            printf("Wrong token content.\n") ;
            return 0;
        }

        release_token(&result);
    }

    fclose(f);

    return 1;
}

unsigned int test_rollback(void)
{
    unsigned short s, size;
    FILE* f;
    TOKEN* t;

    f = fopen("./files/compengine/rollback.xml", "r");
    size = 5;

    char* contents[] = {
        "class", "Hello", "Howdy, World!", "29", "~"
    };

    TOKEN_TYPE types[] = {
        KEYWORD, VARIABLE, STRING_LITERAL, NUMBER_CONSTANT, IMPLEMENTED_SYMBOL
    };

    for (s = 0; s < size; s++)
    {
        t = get_next_token(f);
        release_token(&t);
    }

    for (s = 0; s < size; s++)
    {
        rollback(f);
    }

    for (s = 0; s < size; s++)
    {
        t = get_next_token(f);

        if (strcmp(contents[s], t->content) != 0)
        {
            printf("Wrong content in rollback.\nExpected: %s\nResult: %s\n", contents[s], t->content);
            release_token(&t);
            return 0;
        }

        if (t->type != types[s])
        {
            printf("Wrong token type in rollback %i\n", s);
            printf("Expected: %i\n", types[s]);
            printf("Result: %i\n", t->type);
            release_token(&t);
            return 0;
        }
        release_token(&t);
    }

    fclose(f);

    return 1;

}


unsigned int test_compparser(void)
{
    unsigned short s, size;

    unsigned int (*tests[]) (void) = {
        test_new_token,
        test_release_token_compengine,
        test_parse_token_compengine,
        test_get_next_token,
        test_rollback
    };

    size = 5;

    for (s = 0; s < size; s++)
    {
        if (!tests[s]())
        {
            printf("Fail in submodule test %i\n", s);
            return 0;
        }

    }
    return 1;
}
