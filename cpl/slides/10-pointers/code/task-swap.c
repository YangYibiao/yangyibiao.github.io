/* task-swap.c: 任务 1 —— 把传值版 swap 改成传址版
   现状: swap 交换的是 a、b 两个副本, main 里的 x、y 不会变.
   任务: 修改 swap 的参数和调用, 让 x、y 真正交换.
   期望输出: 交换后: x=8, y=3
   提示: 函数要改 main 的变量, 就要拿到它们的地址;
         参数改成指针, 调用时传 &x、&y, 函数里用 *a、*b.
   在 TODO 处补完代码. */
#include <stdio.h>

void swap(int a, int b)
{
  /* TODO: 改成能交换调用者变量的版本 (参数用指针) */
  int temp = a;
  a = b;
  b = temp;
}

int main(void)
{
  int x = 3, y = 8;

  swap(x, y);              /* TODO: 传入 x、y 的地址 */
  printf("交换后: x=%d, y=%d\n", x, y);  /* 期望: x=8, y=3 */
  return 0;
}
