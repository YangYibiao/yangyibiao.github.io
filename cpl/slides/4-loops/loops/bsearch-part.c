#include <stdio.h>

int binarySearch(int arr[], int l, int r, int k);
int binarySearchRecursion(int arr[], int l, int r, int k);

int main()
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
    // TODO
}

int binarySearchRecursion(int arr[], int l, int r, int k)
{
    // TODO
}