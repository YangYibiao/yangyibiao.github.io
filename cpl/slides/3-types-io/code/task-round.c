/* task-round.c: 任务 —— 把 double 四舍五入成整数
   任务: 不用 %.0f 打印, 而是得到一个 int 值:
     四舍五入 3.7 → 4, 3.4 → 3, -3.7 → -4
   提示:
     - 强制转换 (int) 是向零截断, 直接转 3.7 得 3
     - 正数: (int)(x + 0.5); 负数: (int)(x - 0.5)
   在 TODO 处补完代码 */
#include <stdio.h>

int main(void)
{
  double x = 3.7;

  /* TODO: 实现四舍五入 (正数), 打印结果 */

  /* TODO: 再试负数 -3.7, 观察截断与修正的差别 */

  return 0;
}
