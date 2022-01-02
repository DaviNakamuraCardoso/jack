#include <stdio.h>
#include "keywords.h"

int main(int argc, const char** argv)
{
    if (get_keyword(argv[1]) == __NOT_KEYWORD)
        printf("%s is not a keyword.\n", argv[1]);
    else 
        printf("%s is a keyword.\n", argv[1]);

    return 0;
}

