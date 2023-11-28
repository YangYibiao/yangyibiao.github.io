#include <stdio.h>
#include <stdlib.h>

int main() {
    int **p = malloc(100);
    printf("%p\n", p);
    p++;
    printf("%p\n", p); // ???
}