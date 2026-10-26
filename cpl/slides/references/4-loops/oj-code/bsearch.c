#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x);
int binarySearchRecursion(int arr[], int l, int r, int x);

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int k = 10;
    scanf("%d", &k);
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, k);
    if (result == -1) {
      printf("Element is not present in array\n"); 
    } else {    
      printf("Element is present at index %d\n", result);
    }
    return 0;
}

int binarySearch(int arr[], int l, int r, int k)
{
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == k)
            return m;

        if (arr[m] < k)
            l = m + 1;
        else
            r = m - 1;
    }
 
    return -1;
}

int binarySearchRecursion(int arr[], int l, int r, int k)
{
    if (l > r) {
        return -1;
    }

    int m = (l + r) / 2;
    if (k == arr[m]) {
        return m;
    } else {
        if (k < arr[m]) {
            return binarySearchR(arr, l, m - 1, k);
        } else {
            return binarySearchR(arr, m + 1, r, k);
        }
    }
}