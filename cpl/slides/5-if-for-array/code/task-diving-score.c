/* task-diving-score.c: 习题 —— 跳水评分
   任务: 8 个裁判打分 (0~10, 一位小数), 去掉一个最高分和一个最低分,
         输出剩余 6 个的平均分 (保留两位小数)
   样例:
     输入 8 个分数: 9.5 9.0 8.5 9.5 8.0 9.0 9.5 8.5
     最终得分: 9.00
   提示:
     - 循环里同时维护 sum、max、min 三个量
     - max 初值 -1、min 初值 11: 比所有可能分数都"更差"的起点
     - 最后输出 (sum - max - min) / 6
   在 TODO 处补完代码, 编译运行对照样例 */
#include <stdio.h>

int main(void)
{
  double score, sum = 0, max = -1, min = 11;
  int i;

  printf("输入 8 个分数: ");

  /* TODO: 用 for 循环读入 8 个分数, 累加并更新 max / min */

  /* TODO: 输出 (sum - max - min) / 6, 保留两位小数 */

  return 0;
}
