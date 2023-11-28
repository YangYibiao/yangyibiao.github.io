#include <stdio.h>
#include <stdlib.h>

int main() {
    // p is a pointer, the pointer is points to an array, and the array has two pointers
    int *(*p)[2] = (int *)malloc(100 * sizeof(int)); 
    printf("%p\n", p);
    p++;
    printf("%p\n", p); // ???
}