/* task-round.c: 任务 —— 把一个正实数四舍五入成整数
   任务: 读入一个正实数 x, 输出它四舍五入后的整数
   样例:
     输入: 3.7   → 输出: 4
     输入: 3.4   → 输出: 3
     输入: 2.5   → 输出: 3
   提示:
     - printf("%.0f") 只是打印时四舍五入, 变量本身还是 double
     - 强制转换 (int) 是向零截断: (int)3.7 得 3
     - 先 +0.5 再截断: (int)(x + 0.5)
   在 TODO 处补完代码 */
#include <stdio.h>

int main(void)
{
  double x;

  /* TODO: 读入正实数 x (scanf 用 %lf) */

  /* TODO: 用 (int)(x + 0.5) 得到四舍五入后的整数并输出 */

  return 0;
}
