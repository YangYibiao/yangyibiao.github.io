/* task-palindrome.c: 任务 —— 回文数
   任务: 输入一个正整数, 判断它正着读和倒着读是否一样
   样例:
     输入: 1221
     输出: 1221 是回文数
     输入: 1234
     输出: 1234 不是回文数
   提示:
     - 把数字逐位拆进数组 (个位在前), 用 len 记位数
     - 第 i 位对应倒数第 i 位: digits[i] 与 digits[len - 1 - i]
     - 只比较前 len/2 组; 发现不等就可以提前判 "不是"
   在 TODO 处补完代码 */
#include <stdio.h>

int main(void)
{
  long n, m;
  int digits[20], len = 0, i;

  printf("输入一个整数: ");
  scanf("%ld", &n);

  m = n;
  /* TODO: 用 do-while 把 m 的每一位拆进 digits[], 同时维护 len */

  /* TODO: 首尾对称比较; 不等则输出 "不是回文数" 并提前 return 0 */

  printf("%ld 是回文数\n", n);
  return 0;
}
