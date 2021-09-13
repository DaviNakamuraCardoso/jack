#include <stdio.h>
#include <stdlib.h>

unsigned int compare(void); 

int main(void)
{
    if (compare()) printf("Error in test.\n");

    return 0;
}
    

unsigned int compare(void)
{
    FILE* out, *tst;
    system("cd ..");
    system("make && ./jackvm tests/");

    out = fopen("tests/out", "r");
    tst = fopen("tests/tst", "r");

    char o, t;
    while ((o = fgetc(out)) != EOF &&
           (t = fgetc(tst)) != EOF)
    {
        if (o != t) return 1;
    }

    return o != t;

}
