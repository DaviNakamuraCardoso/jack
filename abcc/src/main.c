#include <stdio.h>
#include <tokenizer.h>

int main(int argc, char** argv)
{
    FILE* f;
    const char* filename = argv[1];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: abcc <filename>\n");
        return 1;
    } 
    
    f = fopen(filename, "r");

    if (f == NULL) 
    {
        fprintf(stderr, "Could not open file '%s'. Compilation failed.\n", filename);
        return 1;
    }

    tokenize(filename, f);

    fclose(f);
    return 0;
}

