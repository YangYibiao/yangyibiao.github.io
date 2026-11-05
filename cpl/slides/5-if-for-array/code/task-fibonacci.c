/* task-fibonacci.c: 习题 —— 斐波那契数列
   任务: 输入 n, 输出斐波那契数列的前 n 项 (1、1、2、3、5、8、…)
   样例 (n = 10):
     1 1 2 3 5 8 13 21 34 55
   提示:
     - 每项是前两项之和: 同时记住 a、b 两个数
     - 每轮: 打印 a -> 算下一项 t -> a 和 b 各往前挪一格
   在 TODO 处补完代码, 编译运行对照样例 */
#include <stdio.h>

int main(void)
{
  int n, i, a = 1, b = 1, t;

  printf("输入 n: ");
  scanf("%d", &n);

  /* TODO: 循环 n 次, 每次打印 a, 再滚动更新 a、b */

  printf("\n");
  return 0;
}
