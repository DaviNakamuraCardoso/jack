#include <stdio.h>
#include <tokenizer.h>
#include <pp.h>

int main(int argc, char** argv)
{
    const char* filename = argv[1];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: abcc <filename>\n");
        return 1;
    } 

    tokenize(filename); 

    return 0;
}

