/* task-repdigit.c: 任务 —— 检查重复数字
   任务: 输入一个正整数, 判断它的各位数字里有没有重复出现的
   样例:
     输入: 28245
     输出: 有重复数字
     输入: 12345
     输出: 没有重复数字
   提示:
     - 用 digit_seen[10] 标志数组: 下标是数字 0~9, 值 0/1 表示出现过没有
     - 每次取 n % 10, 先查表; 已出现就判重复, 否则标记后 n /= 10
     - 数字可能超过 10 位, 用 long 读入 (%ld)
   在 TODO 处补完代码 */
#include <stdio.h>

int main(void)
{
  int digit_seen[10] = {0};
  int digit;
  long n;

  printf("输入一个数: ");
  scanf("%ld", &n);

  /* TODO: while 循环逐位拆数字; 用 digit_seen 查重并标记 */

  /* TODO: 根据是否发现重复, 输出 "有重复数字" 或 "没有重复数字" */

  return 0;
}
