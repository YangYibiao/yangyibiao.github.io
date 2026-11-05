/* combination.c: 课堂挑战——组合数 C(m,n)
   任务: 补全 long combination(int m, int n), 用 factorial 计算
         C(m,n) = m! / (n! * (m-n)!)
   样例: C(5,2) = 10, C(10,3) = 120
   提示: factorial 已经给出, 直接调用三次; main → combination → factorial
         形成两层调用链.
   思考: m = 30 时结果为什么不对? (30! 超出 long 的容量) */
#include <stdio.h>

long factorial(int n)
{
  long f = 1;
  int i;

  for (i = 2; i <= n; i++) {
    f = f * i;
  }
  return f;
}

long combination(int m, int n)
{
  /* TODO: 用 factorial 计算 C(m,n) = m! / (n! * (m-n)!) */
  return 0;
}

int main(void)
{
  printf("%ld\n", combination(5, 2));    /* 期望输出: 10 */
  printf("%ld\n", combination(10, 3));   /* 期望输出: 120 */
  return 0;
}
