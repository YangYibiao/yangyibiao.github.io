#include <stdio.h>

void printArr(int [], int);

void merge(int [], int [], int [], int, int);

int main() {
    int arrA[5] = {1, 2, 3, 4, 5};
    int arrB[5] = {2, 3, 7, 8, 10};
    int arr[10] = {0};

    merge(arrA, arrB, arr, 5, 5);
    printArr(arr, 10);

    return 0;
}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arrA[], int arrB[], int arr[], int aLen, int bLen) {
    // TODO
    return;
}