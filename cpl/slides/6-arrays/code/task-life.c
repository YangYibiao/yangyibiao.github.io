/* task-life.c: 任务 —— 生命游戏 (一代更新)
   任务: 5×5 网格, 初始为竖着的三连; 按规则算出下一代并打印
   规则:
     - 活细胞: 2 或 3 个活邻居 -> 继续活, 否则死
     - 死细胞: 恰好 3 个活邻居 -> 复活
   样例:
     .....        .....
     ..#..        .....
     ..#..   -->  .###.
     ..#..        .....
     .....        .....
   提示:
     - 从 old_grid 数邻居, 写进 new_grid; 两张表不能合并
     - 邻居是 3×3 邻域去掉自己; 越界格子按死细胞处理
     - 打印用 const char cell[] = {'.', '#'} 查表
   在 TODO 处补完代码 */
#include <stdio.h>
#define N 5

int main(void)
{
  int old_grid[N][N] = {0, 0, 0, 0, 0,
                        0, 0, 1, 0, 0,
                        0, 0, 1, 0, 0,
                        0, 0, 1, 0, 0,
                        0, 0, 0, 0, 0};
  int new_grid[N][N];
  const char cell[] = {'.', '#'};
  int i, j, di, dj, count;

  /* TODO: 对每个格子统计 8 邻域的活邻居数, 按规则写入 new_grid */

  /* TODO: 用 cell[] 查表, 按行打印 new_grid */

  return 0;
}
