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

#if 0
    token_t** ts = tokenize(filename); 
    for (size_t i = 0; ts[i] != NULL; i++)
        tkprint(ts[i]);
#else
    tokenize(filename);
#endif

    return 0;
}

