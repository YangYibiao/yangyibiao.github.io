/* task-magic.c: 任务 —— 奇数阶幻方
   任务: 读入奇数 n (3~9), 用 de la Loubère 法构造 n×n 幻方并按行打印
   样例 (n=3):
      8  1  6
      3  5  7
      4  9  2
   提示:
     - 1 放在第一行正中间: i = 0, j = n / 2
     - 每放一个数, 先试右上: ni = (i - 1 + n) % n, nj = (j + 1) % n
     - 右上已被占用就改走正下: i = (i + 1) % n; 否则 i = ni, j = nj
   在 TODO 处补完代码 */
#include <stdio.h>
#define N 9

int main(void)
{
  int magic[N][N] = {0};
  int n, i, j, num;

  printf("输入奇数 n: ");
  scanf("%d", &n);

  i = 0;
  j = n / 2;
  /* TODO: 用 de la Loubère 法把 1 ~ n*n 依次填进 magic[][] */

  /* TODO: 双重循环按行打印 magic[0..n-1][0..n-1], 每格 %3d */

  return 0;
}
