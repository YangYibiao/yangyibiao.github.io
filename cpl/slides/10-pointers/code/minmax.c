#include <stdio.h>
#include <limits.h>

void max_min(int a[], int n, int *max, int *min);

int main() {
  int arr[] = {3, 5, 7, 20, 14, 16};

  int max_value, min_value;
  max_min(arr, sizeof(arr) / sizeof(arr[0]), &max_value, &min_value);
  printf("max: %d, min: %d\n", max_value, min_value);
  return 0;
}

void max_min(int a[], int n, int *max, int *min) {
  *max = INT_MIN; // *max = a[0];
  *min = INT_MAX; // *min = a[0];
  for (int i = 0; i < n; i++) {
    if (*max < a[i]) *max = a[i];
    if (*min > a[i]) *min = a[i];
  }
  return;
}