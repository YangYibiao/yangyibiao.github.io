/* 选择排序: 函数版 */
#include <stdio.h>

void sort(int a[], int n)          /* 把选择排序装进函数 */
{
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    int t = a[i]; a[i] = a[min]; a[min] = t;
  }
}

int main(void)
{
  int a[5] = {5, 2, 4, 1, 3};
  int i;

  sort(a, 5);
  for (i = 0; i < 5; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
