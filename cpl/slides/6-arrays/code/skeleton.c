/* skeleton.c: 6-arrays 课堂编码 —— 按老师指定的任务写, 只补 TODO 处
   任务 A: 统计正数、负数、零的个数 (读入 n, 再读入 n 个整数)
   任务 B: 进制转换 (输入十进制数 n 与进制 base (2~16), 输出转换结果)
   提示: 数组容量用 #define N 100, 实际个数用变量 n */
#include <stdio.h>
#define N 100

int main(void)
{
  int a[N], n, i;

  /* ===== 任务 A: 统计正数、负数、零 ===== */
  {
    int pos = 0, neg = 0, zero = 0;   /* TODO: 读入 n 与 n 个整数, 遍历统计 */
    /* TODO: 输出 "正数 x 个, 负数 y 个, 零 z 个" */
  }

  /* ===== 任务 B: 进制转换 ===== */
  {
    int base;                          /* TODO: 读入 n 与 base */
    /* TODO: 反复 n % base 得到数字, n /= base, 先算出的要后输出 */
  }

  return 0;
}
