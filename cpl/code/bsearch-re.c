#include <stdio.h>

int binary(int arr[], int l, int r, int x);

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < 3; i++) {
        int k = 10;
        scanf("%d", &k);

        int result = binary(arr, 0, n - 1, k);
        if (result == -1) {
            printf("Element is not present in array\n");
        } else {
            printf("Element is present at index %d\n", result);
        }
    }
    return 0;
}

int binary(int arr[], int l, int r, int k)
{
    if (l > r) {
        return -1;
    }

    int m = (l + r) / 2;
    if (k == arr[m]) {
        return m;
    } else {
        if (k < arr[m]) {
            return binary(arr, l, m - 1, k);
        } else {
            return binary(arr, m + 1, r, k);
        }
    }
}