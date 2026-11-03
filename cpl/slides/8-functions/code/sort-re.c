/* 选择排序: 非函数版 */
#include <stdio.h>
#define N 10

void sorting(int arr[], int beg, int end);void print_array(int arr[], int n);

int main(void)
{
  int a[N] = {4, 6, 7, 5, 2, 1, 6, 8, 9, 10};

  print_array(a, N);
  sorting(a, 0, 10);
  print_array(a, N);

  return 0;
}

void sorting(int arr[], int beg, int end) {
  for (int i = beg; i < end - 1; i++) {
    for (int j = beg; j < end - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int t = arr[j]; arr[j] = arr[j+1]; arr[j+1] = t;
      }
    }
    
  }
}

void print_array(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
