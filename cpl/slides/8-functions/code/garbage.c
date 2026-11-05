/* garbage.c: 演示局部变量的"垃圾值"
   运行: cc -std=c11 garbage.c && ./a.out
   现象: i 没有初始化, 打印出来是内存里的残留值, 每次运行可能不同.
   提示: 局部变量不会自动清零; 使用前必须初始化. */
#include <stdio.h>

void f(void)
{
  int i;                 /* 没有初始化 */

  printf("i = %d\n", i); /* 结果不确定 (每次可能不同) */
}

int main(void)
{
  f();
  return 0;
}
