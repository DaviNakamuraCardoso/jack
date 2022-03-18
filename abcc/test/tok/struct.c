#include <stdio.h>
#include <stdint.h>

struct pair {
    long long x, y;
};

int main(void)
{
    struct pair p = {.x=2, .y=7};
    printf("%lli, %lli\n", p.x, p.y);
}
    
