/* stack-overflow.c: 演示没有基准情形的递归 (不规范!)
   打开即编译运行: 每次调用压一张栈帧, 栈空间用尽 → Segmentation fault */
#include <stdio.h>

long fact(int n)
{
  return n * fact(n - 1);     /* 少了基准情形: 永远不返回 */
}

int main(void)
{
  printf("%ld\n", fact(5));
  return 0;
}
