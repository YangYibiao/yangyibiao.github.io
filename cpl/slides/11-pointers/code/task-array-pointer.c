/* task-array-pointer.c: 任务 —— 数组名与指针
   任务: 令 int a[6] = {2, 4, 6, 8, 10, 12};
     1) 用指针 p 从 a 遍历到 a + 6, 求所有元素之和
     2) 对每个下标 i 打印 a[i] 与 *(a + i), 对比两列的值
     3) 打印 a、&a[0]、a + 1、&a[1], 观察数组名与首元素地址的关系
   样例:
     i=0: a[0]=2, *(a+0)=2
     i=5: a[5]=12, *(a+5)=12
     sum = 42
     a = 0x7ffd1a2b, &a[0] = 0x7ffd1a2b
   提示:
     - a + i 等价于 &a[i]; *(a + i) 等价于 a[i]
     - 数组名 a 不能被赋值 (a++ 非法); 遍历时用指针变量 p
   在 TODO 处补完代码 */
#include <stdio.h>

#define N 6

int main(void)
{
  int a[N] = {2, 4, 6, 8, 10, 12};

  /* TODO: 用指针 p 遍历 a[0] ~ a[N-1], 把 *p 累加进 sum */

  /* TODO: 对 i = 0 .. N-1 打印 a[i] 与 *(a + i) */

  /* TODO: 打印 a、&a[0]、a + 1、&a[1] (地址用 %p) */

  return 0;
}
