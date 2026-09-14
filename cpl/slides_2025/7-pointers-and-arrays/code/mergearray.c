#include <stdio.h>
#include <stdlib.h>

void printArr(int *, int);

int *merge(int *, int, int, int);

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 2, 3, 7, 8, 10};

    printf("Before sorting\n");
    printArr(arr, 10);

    int *p = merge(arr, 0, 5, 10);

    printf("After sorting\n");
    printArr(p, 10);

    free(p);
    return 0;
}

int *merge(int *arr, int L, int M, int R) {
    int *nA = (int *) malloc(sizeof(int) * (R - L));
    int *pA = nA;

    int *pL = arr + L;
    int *pR = arr + M;

    while (pL < arr + M && pR < arr + R) {
        if (*pL <= *pR) {
            *pA++ = *pL++;
        } else {
            *pA++ = *pR++;
        }
    }

    while (pL < arr + M) {
        *pA++ = *pL++;
    }
    while (pR < arr + R) {
        *pA++ = *pR++;
    }

    return nA;
}

void printArr(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}