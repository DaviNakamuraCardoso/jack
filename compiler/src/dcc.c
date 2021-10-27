/**
*       Source code for the Davi Compiler Collection (DCC)
*       (c) 2021 Davi Nakamura Cardoso
*/

#include <stdio.h>
#include <stdlib.h>
#include <compengine/analyzer.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage:\n $ dcc <path/to/file.jack>\n or\n $ dcc <path/to/folder>\n"); 
        return 1;
    }
    analyze(argv[1]);
    return 0;
}
