#include <stdio.h>

void max_min(int a[], int n, int *max, int *min);

int main(void) {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int max, min;
    max_min(arr, 10, &max, &min);
    printf("max: %d, min: %d\n", max, min);
}

void max_min(int a[], int n, int *max, int *min)
{
    *max = a[0];
    *min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > *max) {
            *max = a[i];
        }
        if (a[i] < *min) {
            *min = a[i];
        }
    }
}