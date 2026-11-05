/* skeleton.c: 众数统计 —— 现场编码
   任务: 读入 n 个无序整数 (1 <= n <= 100), 输出出现次数最多的数 (众数)
         及其出现次数; 若有多个数并列, 输出最小的那个
   样例:
     输入: 7
           1 2 2 3 2 5 7
     输出: 2 3
   提示:
     - 先排序 (选择 / 冒泡 / 插入任选) —— 相同的数就会相邻
     - 再一遍扫描: cur/cur_cnt 记录当前段, best/best_cnt 记录最优段
     - 最后一段在 i == n 时结算; 用 > 而不是 >= 保证并列时输出最小
   从这行开始写你的代码: 在 TODO 处补完 */
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

  /* TODO: 扫描有序数组, 统计每段长度, 找出现次数最多且最小的众数 */

  printf("%d %d\n", best, best_cnt);
  return 0;
}
