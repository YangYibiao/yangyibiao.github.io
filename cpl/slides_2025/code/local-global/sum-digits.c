#include <stdio.h>

int sum_digits(int n);  /* function prototype */

int main()
{
  int n = 12345;
  for (int i = 0; i < 10; i++) {
    int sum1 = sum_digits(n);
    printf("sum of digits of %d is %d\n", n, sum1);
  }
  
  return 0;
}

int sum_digits(int n)
{
  int sum = 0;   /* local variable */

  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}