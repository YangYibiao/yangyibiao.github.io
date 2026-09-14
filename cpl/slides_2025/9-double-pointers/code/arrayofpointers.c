#include <stdio.h>
#include <stdlib.h>

int main() {
    int * p[3];

    printf("p = %p\n", p);    
    printf("p[0] = %p\n", p[0]);
    printf("p[1] = %p\n", p[1]);
    printf("p[2] = %p\n", p[2]);
    
    p[0] = malloc(10);
    p[1] = malloc(10);
    p[2] = malloc(10);
    
    printf("p = %p\n", p);
    printf("p[0] = %p\n", p[0]);
    printf("p[1] = %p\n", p[1]);
    printf("p[2] = %p\n", p[2]);

    return 0;    
}