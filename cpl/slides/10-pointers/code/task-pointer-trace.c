/* task-pointer-trace.c: 任务 —— 指针追踪
   任务: 令 int a = 3, *p = &a;
     1) 打印 a、&a、p、*p (观察 &a 与 p 是否相同)
     2) 执行 *p = 7, 再打印 a 和 *p (观察 a 是否跟着变)
   样例 (地址每次运行不同):
     a = 3, &a = 0x7ffd1a2b, p = 0x7ffd1a2b, *p = 3
     改写 *p 之后: a = 7, *p = 7
   提示:
     - 打印地址用 %p, 打印整数用 %d
     - &a 是 a 的地址, p 保存的正是这个地址; *p 与 a 是同一块内存
   在 TODO 处补完 printf */
#include <stdio.h>

int main(void)
{
  int a = 3;
  int *p = &a;

  /* TODO: 打印 a、&a、p、*p (一行四个) */

  /* TODO: 执行 *p = 7, 再打印 a 和 *p */

  return 0;
}
