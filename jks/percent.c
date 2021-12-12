#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv)
{
    double total = atof(argv[1]);
    double interest = atof(argv[2]) / 100;
    int time = atoi(argv[3]);

    for (int i = 1; i <= time; i++)
        total += total * interest;
    printf("%f\n", total);

    return 0;
}
    
