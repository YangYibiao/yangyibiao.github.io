/* swap.c: 演示按值传递——swap 交换的只是形参的副本
   运行: cc -std=c11 swap.c && ./a.out
   期望输出: x = 3, y = 5  (外面的 x、y 没有变)
   提示: 函数内的 a、b 是 x、y 的复印件, 交换复印件不影响原件. */
#include <stdio.h>

void swap(int a, int b)
{
  int t = a;
  a = b;
  b = t;
}

int main(void)
{
  int x = 3, y = 5;

  swap(x, y);
  printf("x = %d, y = %d\n", x, y);   /* 期望输出: x = 3, y = 5 */
  return 0;
}
