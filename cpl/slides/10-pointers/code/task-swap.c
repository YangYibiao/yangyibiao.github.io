/* task-swap.c: 任务 1 —— 用 swap 轮换三个数
   目标: 输入 x y z, 轮换为 x=原来的 y, y=原来的 z, z=原来的 x.
   样例输入: 1 2 3
   样例输出: 2 3 1
   提示: 用两次 swap: swap(&x, &y); swap(&y, &z);
   在 TODO 处补完 main 中的轮换. */
#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void)
{
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);

  /* TODO: 用两次 swap 完成轮换 */

  printf("%d %d %d\n", x, y, z);  /* 期望: 2 3 1 */
  return 0;
}
