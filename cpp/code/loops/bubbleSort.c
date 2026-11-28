#include <stdio.h>

void printArr(int [], int);
void bubbleSort(int [], int);

int main() {
    int Arr[9] = {29, 72, 98, 13, 87, 66, 52, 51, 36};

    printArr(Arr, 9);
    bubbleSort(Arr, 9);
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

void bubbleSort(int arr[], int aLen)
{
    for (int i = 0; i < aLen - 1; i++) {
        for (int j = 0; j < aLen - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printArr(arr, aLen);
    }
    return;
}