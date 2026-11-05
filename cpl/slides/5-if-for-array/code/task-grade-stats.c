/* task-grade-stats.c: 习题 —— 成绩等级统计
   任务: 输入一批成绩 (0~100, -1 结束), 统计各等级人数:
         90~100 为 A, 80~89 为 B, 70~79 为 C, 60~69 为 D, 0~59 为 F
   样例:
     输入成绩 (-1 结束): 85 92 78 61 45 92 -1
     A: 2  B: 1  C: 1  D: 1  F: 1
   提示:
     - score / 10 把成绩映射成档位, 用 switch 的 case 分档
     - case 10 和 case 9 共用一个语句 (都是 A)
     - 每个 case 记得 break, 否则会串档
   在 TODO 处补完代码, 编译运行对照样例 */
#include <stdio.h>

int main(void)
{
  int score, a = 0, b = 0, c = 0, d = 0, f = 0;

  printf("输入成绩 (-1 结束): ");

  /* TODO: 读入第一个成绩 */
  /* TODO: 用 while 循环直到 -1, 按 score / 10 分档计数 */
  /* TODO: 输出 A~F 各档人数 */

  return 0;
}
