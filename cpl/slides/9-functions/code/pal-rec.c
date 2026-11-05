/* pal-rec.c: 递归判断回文 —— 只写函数体
   参数设计: l、r = 当前待判断的子串范围 (向中间收缩); 字符串 s 全程不变
   提示: 首尾相等, 且中间一段也是回文
   基准情形: l >= r (只剩 0 或 1 个字符) → 1 */
#include <stdio.h>

int is_pal(char s[], int l, int r)
{
  /* TODO: 基准情形 + 递归情形 */
  if (l >= r) return 1;
  return s[l] == s[r] && is_pal(s, l + 1, r - 1);
}

int main(void)
{
  char s1[] = "level";
  char s2[] = "hello";
  char s3[] = "levael";

  printf("%d\n", is_pal(s1, 0, 4));   /* 期望输出: 1 */
  printf("%d\n", is_pal(s2, 0, 4));   /* 期望输出: 0 */
  printf("%d\n", is_pal(s3, 0, 5));
  return 0;
}
