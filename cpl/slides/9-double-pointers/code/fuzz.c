#include <stdio.h>
#include <stdlib.h>

int main() {
    // p is a pointer, the pointer is points to an array, and the array has two pointers
    int *(*p1)[2] = (int *)malloc(100 * sizeof(int)); 
    printf("p1 = %p\n", p1);
    p1++;
    printf("p1 ++ = %p\n", p1); // ???

    int **p2 = malloc(100);
    printf("%p\n", p2);
    p2++;
    printf("p2 ++ = %p\n", p2); // ???
}