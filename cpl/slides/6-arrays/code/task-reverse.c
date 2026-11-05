/* task-reverse.c: 任务 —— 数列反向
   任务: 输入 10 个整数, 按相反的顺序输出
   样例:
     输入: 34 82 49 102 7 94 23 11 50 31
     输出: 31 50 11 23 94 7 102 49 82 34
   提示:
     - 先用循环把 10 个数读进数组 a
     - 正着存、倒着打: 第二个循环让下标从 N-1 递减到 0
   在 TODO 处补完代码 */
#include <stdio.h>
#define N 10

int main(void)
{
  int a[N], i;

  printf("输入 %d 个数: ", N);
  /* TODO: 用 for 循环读入 N 个整数到 a[i] */

  printf("逆序输出:");
  /* TODO: 下标从 N-1 递减到 0, 逐个打印 a[i] */

  printf("\n");
  return 0;
}
