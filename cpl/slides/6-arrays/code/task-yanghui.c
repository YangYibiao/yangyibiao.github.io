/* task-yanghui.c: 任务 —— 杨辉三角
   任务: 打印杨辉三角的前 6 行 (等腰排列)
   样例:
                 1
               1   1
             1   2   1
           1   3   3   1
         1   4   6   4   1
       1   5  10  10   5   1
   提示:
     - 每行第一个数是 1; 其余 a[i][j] = a[i-1][j-1] + a[i-1][j]
     - 只填下三角 (j <= i), 上半部分靠 {0} 兜底
     - 打印前先输出 N-1-i 组两个空格, 摆成等腰
   在 TODO 处补完代码 */
#include <stdio.h>
#define N 6

int main(void)
{
  int a[N][N] = {0};
  int i, j, k;

  /* TODO: 双重循环填 a[i][j]; 注意 j 从 0 到 i */

  /* TODO: 按行打印, 每行先缩进 N-1-i 组两个空格 */

  return 0;
}
