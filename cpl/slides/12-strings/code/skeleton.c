/* skeleton.c: 列三角函数表, 从这行开始写你的代码 */
#include <stdio.h>
#include <math.h>

/* 在 [a, b] 上以 step 为步长打印 f 的函数值表 */
void tabulate(double (*f)(double), double a, double b, double step)
{
  /* TODO: 计算循环次数, 用 for 循环打印每一行的 x 和 f(x) */
}

int main(void)
{
  double a, b, step;

  printf("输入初值: ");
  scanf("%lf", &a);
  printf("输入终值: ");
  scanf("%lf", &b);
  printf("输入步长: ");
  scanf("%lf", &step);

  printf("\ncos(x):\n");
  tabulate(cos, a, b, step);   /* 期望输出: x 与 cos(x) 的对应表 */

  printf("\nsin(x):\n");
  tabulate(sin, a, b, step);   /* 期望输出: x 与 sin(x) 的对应表 */

  printf("\ntan(x):\n");
  tabulate(tan, a, b, step);   /* 期望输出: x 与 tan(x) 的对应表 */

  return 0;
}
