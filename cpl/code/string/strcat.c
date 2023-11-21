#include<stdio.h>
#include<stdlib.h>

/*
 * Example code for malloc out of memory
 * How many MB space can be allocated?
*/

int count_spaces(const char *s)
{
    int count = 0;
    while (*s != '\0') {
        if (*s == ' ') {
            count++;
        }
        s++;
    }
    return count;
}

void printStr(char *ptr)
{
    while (*ptr) {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
}

size_t strLen(char *ptr) {
    char *nptr = ptr;
    while (*nptr) { nptr++; }
    return (size_t) (nptr - ptr);
}

int stringEqual(const char *s1, const char *s2)
{
    while (*s1 && *s2) {
        if (*s1 != *s2)
            return 0;

        s1++; s2++;
    }
    if (*s1 || *s2) return 0;
    return 1;
}

void strCat(char *des, const char *src)
{
    while (*des) { des++; }
    while (*des++ = *src++);
}

void strCpy(char *des, const char *src)
{
    while (*des++ = *src++);
}

int main(void) {
    char *arr1 = "abcd";
    char *arr2 = (char*)malloc(10 * sizeof(char));
    printString(arr2);

    strCpy(arr2, "abc");
    strCpy(arr2, arr1);
    printString(arr2);
    strCat(arr2, "abc");
    printString(arr2);

    // printCharPtr(arr1);
    // printf("%d", strLen(arr1));

    // if (stringEqual(arr2, arr1)) {
    //     printf("Equal\n");
    // } else {
    //     printf("Not equal\n");
    // }

    // printf("\n%s", arr1);
    // printf("\n%d", count_spaces(arr1));

    return 0;
}