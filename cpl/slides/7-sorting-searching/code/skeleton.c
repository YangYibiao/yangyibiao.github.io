/* skeleton.c: 众数统计 —— 现场编码
   任务: 读入 n 个无序整数 (1 <= n <= 100), 输出出现次数最多的数 (众数)
         及其出现次数; 若有多个数并列, 输出最小的那个
   样例:
     输入: 7
           1 2 2 3 2 5 7
     输出: 2 3
   提示: 排序之后, 相同的数会相邻; 想一想怎样在一次扫描里统计每一段.
   在 TODO 处补完代码 */
#include <stdio.h>
#define N 100

int main(void)
{
  int a[N], n, i;
  int best = 0, best_cnt = 0;   /* TODO: 扫描后填入真正的众数与次数 */

  printf("输入个数: ");
  scanf("%d", &n);
  printf("输入 %d 个数: ", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  /* TODO: 排序 (选择 / 冒泡 / 插入, 任选一种) */

  /* TODO: 扫描有序数组, 找出出现次数最多的数 (并列取最小) */

  printf("%d %d\n", best, best_cnt);
  return 0;
}
