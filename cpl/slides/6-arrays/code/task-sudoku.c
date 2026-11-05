/* task-sudoku.c: 任务 —— 数独校验
   任务: 读入 9×9 数独 (每格 1~9), 判断每行/每列/每个 3×3 宫
         是否都恰好是 1~9 各一次
   样例输出:
     Right   (合法)
     Wrong   (有重复)
   提示:
     - 三次扫描用同一招: seen[10] 标志数组查重
     - 行/列: seen[board[i][j]]; 发现重复就置 ok = 0 提前结束
     - 九宫格: i、j 每次加 3, 用 k = 0..8 扫 board[i + k/3][j + k%3]
   在 TODO 处补完代码 */
#include <stdio.h>
#define N 9

int main(void)
{
  int board[N][N];
  int i, j, k, ok = 1;

  /* TODO: 读入 9×9 个整数 */

  /* TODO: 分别校验每行、每列、每个 3×3 宫 (标志数组查重) */

  printf(ok ? "Right\n" : "Wrong\n");
  return 0;
}
