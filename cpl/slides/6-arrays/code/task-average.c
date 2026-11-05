/* task-average.c: 任务 —— 平均分与高于平均
   任务: 输入 10 个成绩, 输出平均分 (保留 1 位小数) 和高于平均分的人数
   样例:
     输入: 5 8 3 8 2 9 1 9 9 4
     输出: 平均分 5.8, 高于平均 5 人
   提示:
     - 第一遍读入时顺便求和; 平均分 = sum / (double) N (整数除法会截断)
     - 成绩必须先存进数组: 算完平均分, 还要回头比第二遍
   在 TODO 处补完代码 */
#include <stdio.h>
#define N 10

int main(void)
{
  int score[N], i, sum = 0, count = 0;
  double avg;

  printf("输入 %d 个成绩: ", N);
  /* TODO: 读入 N 个成绩, 同时累加到 sum */

  /* TODO: 计算 avg = sum / (double) N */

  /* TODO: 第二遍遍历, 统计 score[i] > avg 的人数到 count */

  printf("平均分 %.1f, 高于平均 %d 人\n", avg, count);
  return 0;
}
