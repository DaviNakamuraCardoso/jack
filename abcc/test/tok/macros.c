#include <stdio.h>
#include <stdlib.h>

#ifndef __T
#define __T
#define begin {
#define end } 
#endif 

int main(void) begin
    printf("Hello, World!\n");

    while (1) begin 
        puts("Hey");
    end
end
