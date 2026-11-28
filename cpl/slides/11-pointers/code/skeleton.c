/* skeleton.c: 从这行开始写你的代码 */
#include <stdio.h>

int find_sum(int *a, int n) {
  /* TODO: 用指针遍历数组, 返回所有元素之和 (不要用下标 a[i]) */
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += *(a + i);
  }
  // for (int *p = a; p < (a + n); p++) {
  //   sum += *p;
  // }
  return sum;
}

int find_max(int *a, int n) {
  /* TODO: 用指针遍历数组, 返回最大元素 (不要用下标 a[i]) */
  int max = *a;
  for (int i = 0; i < n; i++) {
    if (max < *(a + i)) {
      max = *(a + i);
    }
  }
  // for (int *p = a; p < a + n; p++) {
  //   if (*p > max) {
  //     max = *p;
  //   }
  // }
  return max;
}

int main(void) {
  int b[10] = {34, 82, 49, 102, 7, 94, 23, 11, 50, 31};
  printf("sum = %d\n", find_sum(b, 10));   /* 期望输出: sum = 483 */
  printf("max = %d\n", find_max(b, 10));   /* 期望输出: max = 102 */
  return 0;
}
