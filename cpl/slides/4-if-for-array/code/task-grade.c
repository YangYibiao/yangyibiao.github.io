/* task-grade.c: 任务 —— 成绩等级
   任务: 输入百分制成绩 (0-100 的整数), 输出等级 A/B/C/D/F
   样例:
     请输入成绩: 87
     等级: B
   等级规则:
     90-100 A, 80-89 B, 70-79 C, 60-69 D, 0-59 F
   提示:
     - 用 switch (score / 10) 把分数段变成 10、9、8……
     - 多个 case 可以共用一组语句; 每个分支别忘 break
     - 先检查成绩是否在 0-100, 非法输入单独处理
   在 TODO 处补完代码 */
#include <stdio.h>

int main(void)
{
  int score;

  /* TODO: 提示并读入成绩 (scanf("%d", &score)) */

  /* TODO: 先判断 0 <= score <= 100, 非法成绩直接输出 "成绩非法" */

  /* TODO: 用 switch (score / 10) 输出对应等级, 注意每个分支的 break */

  return 0;
}
