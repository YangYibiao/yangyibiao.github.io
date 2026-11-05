/* 选择排序: 非函数版 (改造前)
   任务: 把排序逻辑抽成函数 sort(a, n), main 只剩读入、调用、输出.
   样例: 输入 5 3 9 1 8 2 7 4 6 0 → 输出 0 1 2 3 4 5 6 7 8 9
   提示: 数组怎么传? 长度怎么传? 和 sum_array 是同样的两个问题. */
#include <stdio.h>

int main(void)
{
  int a[10], n = 10;

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    int t = a[i];
    a[i] = a[min];
    a[min] = t;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
