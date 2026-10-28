/* Three tasks: with functions */
#include <stdio.h>

int is_prime(int n)          /* write once */
{
  int d;

  for (d = 2; d * d <= n; d++) {
    if (n % d == 0) {
      return 0;
    }
  }
  return 1;
}

int is_palindrome(int n)     /* write once */
{
  int rev = 0, t = n;

  while (t > 0) {
    rev = rev * 10 + t % 10;
    t = t / 10;
  }
  return rev == n;
}

int main(void)
{
  int m, n, i, count = 0;

  printf("Enter m n (m<=n): ");
  scanf("%d%d", &m, &n);

  for (i = m; i <= n; i++) {
    /* task 1: print palindromic primes */
    if (is_prime(i) && is_palindrome(i)) {
      printf("%d ", i);
    }
    /* task 2: count primes */
    if (is_prime(i)) {
      count++;
    }
  }
  printf("\nPrime count: %d\n", count);

  /* task 3: is n a palindrome? */
  if (is_palindrome(n)) {
    printf("%d is a palindrome\n", n);
  } else {
    printf("%d is not a palindrome\n", n);
  }
  return 0;
}
