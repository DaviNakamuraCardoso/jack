#include <stdio.h>
#include <tokenizer.h>

int main(int argc, char** argv)
{
    FILE* f;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./jks <filename>\n");
        return 1;
    } 
    
    f = fopen(argv[1], "r");

    if (f == NULL) 
    {
        fprintf(stderr, "Could not open file '%s'. Compilation failed.\n", argv[1]);
        return 1;
    }

    tokenize(f);

    fclose(f);
    return 0;
}

