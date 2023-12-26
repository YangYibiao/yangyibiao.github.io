#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;

  return;
}

void qsort(int *arr, int len)
{
  if (len <= 1)
    return;

  int pivot = arr[len - 1]; // last element as pivot
  int i = 0;
  int j = len - 2;

  while (i < j)
  {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;

    if (i < j)
      swap(&arr[i], &arr[j]);
  }

  swap(&arr[i], &arr[len - 1]);

  qsort(arr, i);
  qsort(arr + i + 1, len - i - 1);

  return;
}

int main()
{
  int arr[] = {1, 3, 2, 5, 4};

  int len = sizeof(arr) / sizeof(arr[0]);

  qsort(arr, len);
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}