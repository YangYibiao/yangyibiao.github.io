/* task2-digit-sum.c: 任务 2 —— 各位数字之和
   任务: 输入一个非负整数, 输出它各位数字之和; 0 也要能正确处理
   样例:
     输入一个非负整数: 12345
     各位数字之和 = 15
     输入一个非负整数: 0
     各位数字之和 = 0
   提示:
     - 拆位老办法: % 10 取末位, / 10 去掉末位
     - 至少要做一次——do-while 正合适
     - 想想输入 0 时 while 版会怎样
   在 TODO 处补完代码, 编译运行对照样例 */
#include <stdio.h>

int main(void)
{
  int n, sum = 0;

  printf("输入一个非负整数: ");
  scanf("%d", &n);

  /* TODO: 用 do-while 反复取末位并累加, 直到 n 变成 0 */

  printf("各位数字之和 = %d\n", sum);
  return 0;
}
