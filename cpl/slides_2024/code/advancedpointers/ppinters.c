#include <stdio.h>

int main()
{
    int i;
    int *pi;
    int **ppi;

    i = 10;

    pi = &i;
    ppi = &pi;
    printf("i = %d\n", i);
    printf("&i = %p\n", &i);
    printf("pi = %p\n", pi);
    printf("&pi = %p\n", &pi);
    printf("*pi = %d\n", *pi);
    printf("ppi = %p\n", ppi);
    printf("*ppi = %p\n", *ppi);
    printf("**ppi = %d\n", **ppi);
    ppi++;
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(int*) = %d\n", sizeof(int*));
    printf("sizeof(int**) = %d\n", sizeof(int**));
    printf("sizeof(int***) = %d\n", sizeof(int***));
    printf("ppi++ = %p\n", ppi);

    return 0;
}