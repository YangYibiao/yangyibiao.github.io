/* hanoi.c: 汉诺塔完整程序 —— 3 根柱, n 个盘从 A 移到 C (借 B) */
#include <stdio.h>

void Hanoi(int n, char A, char B, char C)
{
  if (n == 1) {
    printf("(盘子: %d) %c -> %c\n", n, A, C);      /* 基准: 只剩一个盘 */
  } else {
    Hanoi(n - 1, A, C, B);            /* 上面 n-1 个: A -> B (借 C) */
    printf("(盘子：%d) %c -> %c\n", n, A, C);      /* 最大盘: A -> C */
    Hanoi(n - 1, B, A, C);            /* 上面 n-1 个: B -> C (借 A) */
  }
}

int main(void)
{
  Hanoi(8, 'A', 'B', 'C');     /* 3 个盘的完整移法 */
  return 0;
}
