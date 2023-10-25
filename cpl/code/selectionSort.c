#include <stdio.h>

void printArr(int [], int);
void selectionSort(int [], int);

int main() {
    int Arr[9] = {29, 72, 98, 13, 87, 66, 52, 51, 36};

    printArr(Arr, 9);
    selectionSort(Arr, 9);
    printArr(Arr, 9);
    return 0;
}

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int aLen)
{
    for (int i = 0; i < aLen - 1; i++) {
        int jMin = i;
        for (int j = i+1; j < aLen; j++) {
            if (arr[j] < arr[jMin]) {
                jMin = j;
            }
        }

        if (jMin != i) {
            int temp = arr[i];
            arr[i] = arr[jMin];
            arr[jMin] = temp;
        }
    }
    return;
}