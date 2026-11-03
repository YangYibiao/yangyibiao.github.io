/* pal-rec.c: 递归判断回文 —— 只写函数体
   提示: 首尾相等, 且中间一段也是回文
   基准情形: l >= r (只剩 0 或 1 个字符) → 1 */
#include <stdio.h>

int is_pal(char s[], int l, int r)
{
  /* TODO: 基准情形 + 递归情形 */
}

int main(void)
{
  char s1[] = "level";
  char s2[] = "hello";

  printf("%d\n", is_pal(s1, 0, 4));   /* 期望输出: 1 */
  printf("%d\n", is_pal(s2, 0, 4));   /* 期望输出: 0 */
  return 0;
}
