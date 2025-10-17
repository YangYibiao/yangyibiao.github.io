#include <stdio.h>

void printArr(int[], int);

void merge(int[], int, int, int);

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 2, 3, 7, 8, 10};

    printf("Before sorting\n");
    printArr(arr, 10);

    merge(arr, 0, 5, 10);

    printf("After sorting\n");
    printArr(arr, 10);

    return 0;
}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
    int narr[right - left];

    int indexL = left, indexR = mid, curr = 0;
    while (indexL < mid && indexR < right) {
        if (arr[indexL] <= arr[indexR]) {
            narr[curr++] = arr[indexL++];
        } else {
            narr[curr++] = arr[indexR++];
        }
    }

    while (indexL < mid)
        narr[curr++] = arr[indexL++];
    while (indexR < right)
        narr[curr++] = arr[indexR++];

    for (int i = 0; i < right - left; i++) {
        arr[left + i] = narr[i];
    }

    return;
}