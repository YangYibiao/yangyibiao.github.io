#include <stdio.h>

int main(void)
{
  int n;
  long f = 1;

  printf("输入 n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {    /* 计算 n! */
    f = f * i;
  }
  printf("%d! = %ld\n", n, f);
  return 0;
}
