/** Test the cleaner module */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tokenizer/tokens.h>
#include <tokenizer/cleaner.h>

unsigned int test_split_spaces(void)
{
    char* result, *expected;

    expected = "class\nMain\n{\nfunction\nvoid\nmain\n(\n)\n{\n}\n}\n";
    result = split_symbols("class\nMain\n{\nfunction\nvoid\nmain()\n{\n}\n}\n");

    if (strcmp(result, expected) != 0)
    {
        printf("Result: %s\n", result);
        printf("Expected: %s\n", expected);

        free(result);
        return 0;
    }

    free(result);
    return 1;
}

unsigned int test_split_spaces_string_literals(void)
{

    unsigned short size, s;
    char* result;

    char* input[] = {
        "class\nMain\n{\nfunction\nvoid\nmain()\n{\ndo\nOutput.printString(\n\"Hello, World\"\n);\n}\n}\n"
    };

    char* expected[] = {
        "class\nMain\n{\nfunction\nvoid\nmain\n(\n)\n{\ndo\nOutput\n.\nprintString\n(\n\"Hello, World\"\n)\n;\n}\n}\n"
    };

    size = 1;

    for (s = 0; s < size; s++)
    {
        result = split_symbols(input[s]);

        if (strcmp(result, expected[s]) != 0)
        {
            printf("Result: %s\n", result);
            printf("Expected: %s\n", expected[s]);
            free(result);
            return 0;
        }

        free(result);
    }


    return 1;

}

unsigned int test_string_or_constant(void)
{
    unsigned short s, size;
    char* input[] = {
        "goto",
        "\"Hello, World\"",
        "9223",
        "$hello",
        "\"String\""
    };

    TOKEN_TYPE expected[] = {
        -1,
        STRING_LITERAL,
        NUMBER_CONSTANT,
        -1,
        STRING_LITERAL

    };
    size = 5;

    for (s = 0; s < size; s++)
    {
        if (string_or_constant(input[s]) != expected[s])
        {
            printf("Error in string_or_constant\n");
            return 0;
        }
    }

    return 1;
}

unsigned int test_variable_checker(void)
{
    unsigned short s, size;

    char* variables[] = {
        "i",
        "hello_world",
        "9hello",
        "HELLO",
        "$hello"
    };

    TOKEN_TYPE types[] = {
        VARIABLE,
        VARIABLE,
        -1,
        VARIABLE,
        -1
    };

    size = 5;

    for (s = 0; s < size; s++)
    {
        if (check_variable(variables[s]) != types[s])
        {
            printf("Error in check_variable.\n");
            return 0;
        }
    }

    return 1;
}


unsigned int test_cleaner(void)
{
    unsigned short i, size;

    unsigned int (*tests[]) (void) = {
        test_split_spaces,
        test_split_spaces_string_literals,
        test_string_or_constant,
        test_variable_checker
    };

    size = 4;
    for (i = 0; i < size; i++)
    {
        if (!tests[i]())
        {
            printf("Error in comparison %i\n", i);
            return 0;
        }
    }

    return 1;
}
