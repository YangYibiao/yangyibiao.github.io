/* 选择排序: 非函数版 */
#include <stdio.h>

void sort(int arr[], int beg, int end) {
  for (int i = beg; i < end - 1; i++) {
    int min = i;
    for (int j = i + 1; j < end; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    int t = arr[i]; arr[i] = arr[min]; arr[min] = t;
  }
}

void print_arr(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main(void)
{
  int a[10] = {3, 5, 2, 6, 7, 9, 4, 6};

  print_arr(a, 10);
  sort(a, 3, 7);
  print_arr(a, 10);

  printf("\n");
  return 0;
}
