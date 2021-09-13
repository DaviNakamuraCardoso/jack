/**
*       Test the precompilation process
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tokenizer/precomp.h>
#include <tokenizer/reader.h>

unsigned int compare_results(char** input, char** expected,
    int size, char* (*tested_function) (char*))
{
    int i;
    char* msg;

    for (i = 0; i < size; i++)
    {
        msg = tested_function(input[i]);
        if (strcmp(msg, expected[i]) != 0)
        {
            printf("Fail parsing %i.\n", i);
            printf("Input: %s\n", input[i]);
            printf("Expected: %s\n", expected[i]);
            printf("Returned: %s\n", msg);
            return 0;
        }
    }
    return 1;
}

static unsigned int can_handle_whitespaces(void)
{
    int i;
    unsigned int result;

    char* messages[] = {
        "   let a = b;",
        "  do a();",
        "class Java {}",
        "",
        "   switch (card)",
        "my %wife;   "

    };

    char* expected[] = {
        "let a = b;",
        "do a();",
        "class Java {}",
        "",
        "switch (card)",
        "my %wife;   "

    };

    return (compare_results(messages, expected, 6, handle_whitespaces));
}

unsigned int can_handle_inline_comments(void)
{
    unsigned int result;

    char* msgs[] = {
        "// This is an inline comment\n",
        "// Sets a to b\nmy a = b;",
        "\ni++; // increase i by 1",
        "// Check if file is null\nbool checkIfFileIsNull(File f)\n",
        "// Assignment\na = a / b;\n",
        ""

    };

    char* expec[] = {
        "",
        "my a = b;",
        "\ni++; // increase i by 1",
        "bool checkIfFileIsNull(File f)\n",
        "a = a / b;\n",
        ""
    };


    return compare_results(msgs, expec, 6, handle_inline_comments);
}

unsigned int can_handle_multiple_line_comments(void)
{
    unsigned int result;

    char* msgs[] = {
        "/** This is a JavaDoc */\nclass Hello {\n",
        "/***/",
        "typedef struct _hello {",
        "/**HELLO**/create_hello(char* msg)\n",
        "a *= b / a * c / */(a**2)\n",
        ""
    };

    char* expected[] = {
        "\nclass Hello {\n",
        "",
        "typedef struct _hello {",
        "create_hello(char* msg)\n",
        "a *= b / a * c / */(a**2)\n",
        ""
    };


    return compare_results(msgs, expected, 6, handle_multiple_line_comments);
}

unsigned int can_clean_source(void)
{
    short size, i;
    char filename[200], *output_file, *expected, *source;

    expected = "class\nMain\n{\nfunction\nvoid\nmain()\n{\n}\n}\n";

    size = 3;

    for (i = 0; i < size; i++)
    {
        sprintf(filename, "files/tokenizer/precompile_test%i.jack", i);
        source = get_file(filename);
        output_file = clean_source(source);

        if (strcmp(expected, output_file) != 0)
        {
            printf("Fail in test %i\n", i);
            printf("Output is %s\n", output_file);
            return 0;
        }

        free(source);
        free(output_file);
    }

    return 1;
}

unsigned int can_clean_string_literals(void)
{
    short size, s;
    char filename[200], *output, *expected, *source;

    expected = "class\nMain\n{\nfunction\nvoid\nmain()\n{\ndo\nOutput.printString(\n\"Hello, World\"\n);\n}\n}\n";

    size = 1;

    for (s = 0; s < size; s++)
    {
        sprintf(filename, "files/tokenizer/string_literals_test_%i.jack", s);
        source = get_file(filename);
        output = clean_source(source);

        if (strcmp(output, expected) != 0)
        {
            printf("Error in test %i\n", s);
            printf("Output is %s\n", output);
            free(output);
            return 0;
        }


        free(source);
        free(output);
    }

    return 1;
}

unsigned int can_precompile(void)
{
    unsigned short s, size;
    char filename[200], *result, *expected;

    size = 5;
    expected = "class\nMain\n{\nfunction\nvoid\nmain\n(\n)\n{\n}\n}\n";
    for (s = 0; s < size; s++)
    {
        sprintf(filename, "files/tokenizer/precompile_%i.jack", s);
        result = precompile(filename);

        if (strcmp(result, expected) != 0)
        {
            printf("Output: %s", result);
            printf("Expected: %s\n", expected);
            free(result);
            return 0;
        }
        free(result);
    }

    return 1;
}

unsigned int test_precomp(void)
{
    int size, i;

    unsigned int (*tests[]) (void) = {
        can_handle_whitespaces,
        can_handle_inline_comments,
        can_handle_multiple_line_comments,
        can_clean_source,
        can_clean_string_literals,
        can_precompile
    };

    size = 6;

    printf("Running precomp tests.\n");
    for (i = 0; i < size; i++)
    {
        if (!tests[i]()) return 0;
    }

    return 1;

}
