/* task-convert.c: 任务 —— 隐式转换与强制转换实验
   任务: 观察并解释下面几组输出:
     1) int 转 double: 7 / 2 与 7 / 2.0 的结果
     2) char 转 int: 'A' 当整数打印是多少
     3) 负数转 unsigned: (unsigned)-1 打印 %u 是多少
     4) 强制转换截断: (int)3.99 与 (int)-3.99 是多少
   样例 (常见结果):
     7 / 2 = 3, 7 / 2.0 = 3.5
     'A' 的整数值 = 65
     (unsigned)-1 = 4294967295
     (int)3.99 = 3, (int)-3.99 = -3   (向零截断, 不是四舍五入)
   提示:
     - 混合类型运算会先转换; 负数转无符号是"按 2 的幂取模"
   在 TODO 处补完 printf */
#include <stdio.h>

int main(void)
{
  /* TODO: 四组实验各打印一行, 先预测再运行 */

  return 0;
}
