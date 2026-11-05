/* task-perfect-number.c: 习题 —— 完全数判定
   任务: 输入一个整数, 判断它是不是完全数
         (等于除自身外所有因数之和, 如 6 = 1+2+3)
   样例:
     输入一个数: 28
     28 是完全数
     输入一个数: 12
     12 不是完全数
   提示:
     - 枚举 1 ~ n-1, n % i == 0 就是因数
     - 用 sum 累加所有因数, 循环结束后与 n 比较
   在 TODO 处补完代码, 编译运行对照样例 */
#include <stdio.h>

int main(void)
{
  int n, i, sum = 0;

  printf("输入一个数: ");
  scanf("%d", &n);

  /* TODO: 用 for 枚举 1 ~ n-1, 把因数累加进 sum */

  /* TODO: 判断 sum 是否等于 n 并输出结论 */

  return 0;
}
