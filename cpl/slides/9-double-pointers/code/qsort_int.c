#include <stdio.h>
#include <stdlib.h>

int cmp_int_asc(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int main() {
  int arr[] = {42, 13, 77, 9, 56};
  int n = sizeof(arr) / sizeof(arr[0]);

  qsort(arr, n, sizeof(int), cmp_int_asc);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}