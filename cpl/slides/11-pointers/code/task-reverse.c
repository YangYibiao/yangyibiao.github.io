/* task-reverse.c: 现场演示 —— 数列反向 (指针版)
   任务: 输入 10 个整数, 用指针逆序输出, 全程不用下标 a[i]
   样例:
     输入 10 个数: 34 82 49 102 7 94 23 11 50 31
     逆序输出: 31 50 11 23 94 7 102 49 82 34
   提示:
     - 读入: p 从 a 走到 a + N, scanf("%d", p)
     - 输出: p 从 a + N 开始, 先 --p 再打印, 直到 p == a
   在 TODO 处补完两个循环 */
#include <stdio.h>

#define N 10

int main(void)
{
  int a[N], *p;

  printf("输入 %d 个数: ", N);

  /* TODO: 用指针 p 读入 N 个整数 */

  printf("逆序输出:");

  /* TODO: 用指针 p 从后往前打印 N 个整数 */

  printf("\n");
  return 0;
}
