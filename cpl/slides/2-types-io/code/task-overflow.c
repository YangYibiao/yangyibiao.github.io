/* task-overflow.c: 任务 —— 整数溢出实验
   任务:
     1) 打印 INT_MAX, 再打印 INT_MAX + 1, 观察结果
     2) 读入一个很大的整数并乘以 2, 看会发生什么
   样例 (常见 32 位 int):
     INT_MAX     = 2147483647
     INT_MAX + 1 = -2147483648
   提示:
     - #include <limits.h> 后用 INT_MAX
     - 溢出是"绕圈"——最大数加一回到最小数, 这正是补码环
     - 注意: 有符号整数溢出在 C 标准里是未定义行为, 本实验只是观察常见实现
   在 TODO 处补完代码 */
#include <stdio.h>
#include <limits.h>

int main(void)
{
  /* TODO: 打印 INT_MAX 与 INT_MAX + 1 */

  /* TODO: 读入一个整数 n, 打印 n * 2 */

  return 0;
}
