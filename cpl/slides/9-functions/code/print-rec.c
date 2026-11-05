/* print-rec.c: 递归按位打印整数 —— 只写函数体
   问题: 输入 1234, 按位逐个打印 → 1 2 3 4 (数字之间一个空格)
   提示: 先递归打印 n/10 (前面几位), 回来再打印 n%10 (末位)——顺序是关键
   基准情形: 一位数 (n / 10 == 0) 直接打印 */
#include <stdio.h>

void print(int n)
{
  /* TODO: 基准情形 + 递归情形 */
}

int main(void)
{
  print(1234);    /* 期望输出: 1 2 3 4 */
  printf("\n");
  print(7);       /* 期望输出: 7 */
  printf("\n");
  return 0;
}
