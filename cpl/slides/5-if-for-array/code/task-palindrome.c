/* task-palindrome.c: 习题 —— 回文数判定
   任务: 输入一个正整数, 判断它是不是回文数 (正着读和反着读一样)
   样例:
     输入一个数: 12321
     12321 是回文数
     输入一个数: 12345
     12345 不是回文数
   提示:
     - 把数"反过来读": 用 rev = rev * 10 + m % 10 逐位拼
     - m 复制 n, n 要留到最后比较, 不能改
   在 TODO 处补完代码, 编译运行对照样例 */
#include <stdio.h>

int main(void)
{
  int n, m, rev = 0;

  printf("输入一个数: ");
  scanf("%d", &n);

  /* TODO: 用 m 复制 n, 循环拆位构造 rev */

  /* TODO: 比较 rev 与 n, 输出结论 */

  return 0;
}
