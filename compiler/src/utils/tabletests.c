/**
*
*          Useful functions to test the symbol table
*
*
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <compengine/compile.h>
#include <compengine/structure.h>
#include <utils/tests.h>

unsigned int test_symbols(char* name, __VARIABLE** variables[], int size, void (*tested) (CODE*))
{
    char filename[200], filename2[200], filename3[200];
    FILE* input, *output;
    CODE* c;

    for (int i = 0; i < size; i++)
    {
        set_filenames(name, filename, filename2, filename3, i);
        input = fopen(filename, "r");
        output = fopen(filename2, "w");

        c = new_code(input, output, NULL);
        c->table = new_table("Main");

        tested(c);

        for (int j = 0; variables[i][j] != NULL; j++)
        {
            __VARIABLE* found = search_table(c->table, variables[i][j]->name);


            if (found == NULL)
            {
                printf("%s\n", variables[i][j]->name); 
                fprintf(stderr, "Variable wasn't added to table.\n");
                return 0;
            }

            if (found->type != variables[i][j]->type)
            {
                fprintf(stderr, "Wrong type.\n");
                return 0;
            }

            if (found->kind != variables[i][j]->kind)
            {
                fprintf(stderr, "Wrong variable kind\n");
                return 0;
            }

            release_variable(variables[i][j]);
        }

        release_code(c);

    }

    return 1;
}
