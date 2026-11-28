#include <stdio.h>

int sumRecursive(int arr[], int start, int left);

int main()
{
    int arr[] = { 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int r = sumRecursive(arr, 0, n);
    printf("%d", r);
    return 0;
}

int sumRecursive(int arr[], int start, int left)
{
    if (left == 0) {
        return 0;
    }
    else if (left == 1) {
        return arr[start];
    } else {
        return arr[start] + sumRecursive(arr, start + 1, left - 1);
    }
}