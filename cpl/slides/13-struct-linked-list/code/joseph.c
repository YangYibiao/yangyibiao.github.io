/* joseph.c: 约瑟夫问题 (循环链表) —— 只写 main 中的建环与出列
   任务: n 个人围成一圈 (编号 1~n), 从 1 号开始报数, 报到 m 的人出列;
         下一个人继续从 1 报起, 直到只剩一人, 输出出列顺序与幸存者.
   样例: 输入 7 3
         期望输出: 3 6 2 7 5 1 4
                   幸存者: 4
   提示: ① 头插法建 n 个结点, 找尾结点让 next 指向 first 连成环;
         ② prev 从 first 出发, 每轮走 m-1 步, prev->next 就是出列者;
         ③ 输出后 prev->next = prev->next->next 并 free, prev 不动;
         ④ 直到 prev->next == prev 停止. */
#include <stdio.h>
#include <stdlib.h>

struct node {
  int no;              /* 编号 */
  struct node *next;
};

int main(void)
{
  int n, m;
  struct node *first = NULL, *prev = NULL, *p = NULL;

  if (scanf("%d %d", &n, &m) != 2 || n < 1 || m < 1) {
    printf("输入无效\n");
    return 1;
  }

  /* TODO: 建 n 个结点 (编号 1~n), 用头插法连成单链表 */
  /* TODO: 找尾结点, 让尾结点的 next 指向 first, 连成循环链表 */
  /* TODO: prev 从 first 出发, 每轮走 m-1 步; 输出并删除 prev->next;
           直到 prev->next == prev */
  /* 期望输出: 3 6 2 7 5 1 4
              幸存者: 4 */

  (void)first;
  (void)prev;
  (void)p;
  return 0;
}
