#include <stdio.h>

int binarySearchR(int arr[], int l, int r, int x);

int minRecursive(int arr[], int s, int n);

int main(void)
{
    int arr[] = { 3, 5, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int r = minRecursive(arr, 0, n);
    printf("%d is the minimal value\n", r);
    return 0;
}

int minRecursive(int arr[], int start, int left)
{
    if (left == 2) {
        if (arr[start] <= arr[start + 1]) {
            return arr[start];
        } else {
            return  arr[start + 1];
        }
    } else {
        int m = minRecursive(arr, start + 1, left - 1);
        return arr[start] <= m ? arr[start] : m;
    }
}