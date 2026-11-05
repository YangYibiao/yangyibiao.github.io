/* task-number-triangle.c: 习题 —— 数字三角形
   任务: 输入高度 n, 打印数字三角形——第 i 行打印 i 个数字 i
   样例 (n = 4):
     1
     22
     333
     4444
   提示:
     - 嵌套循环: 外层管行, 内层管每行个数
     - 内层打印的是外层变量 i (行号), 不是内层变量 j
   在 TODO 处补完代码, 编译运行对照样例 */
#include <stdio.h>

int main(void)
{
  int n;

  printf("输入高度: ");
  scanf("%d", &n);

  /* TODO: 外层 for 控制行 i = 1..n */
  /* TODO: 内层 for 每行打印 i 个数字 i */
  /* TODO: 每行结束换行 */

  return 0;
}
