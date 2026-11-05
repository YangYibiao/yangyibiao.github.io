/* task4-change.c: 任务 4 —— 找零计算
   样例:
     请输入金额 (元): 386
     100元: 3 张
      50元: 1 张
      20元: 1 张
      10元: 1 张
       5元: 1 张
       1元: 1 张
   提示:
     - amount / 100 得"有几个 100"; amount % 100 得"剩下多少"
     - 每一步先算张数, 再用 % 更新 amount, 一层层拆下去
   在 TODO 处补完代码 (100/50/20/10/5/1 六种面额, 注意输出对齐) */
#include <stdio.h>

int main(void)
{
  int amount;

  /* TODO: 提示并读入金额 (scanf("%d", &amount)) */

  /* TODO: 依次处理 100、50、20、10、5 元:
       printf 张数 (amount / 面额), 再 amount = amount % 面额 */

  /* TODO: 最后打印 1 元张数 (此时的 amount) */

  return 0;
}
