/* Three tasks: no functions */
#include <stdio.h>

int main(void)
{
  int m, n, i, d, rev, t;
  int count = 0;

  printf("Enter m n (m<=n): ");
  scanf("%d%d", &m, &n);

  for (i = m; i <= n; i++) {
    /* task 1: print palindromic primes */
    /*   prime check (1st time) */
    int is_prime = 1;
    for (d = 2; d * d <= i; d++)
      if (i % d == 0) { is_prime = 0; break; }
    /*   palindrome check (1st time) */
    t = i; rev = 0;
    while (t > 0) { rev = rev * 10 + t % 10; t = t / 10; }
    if (is_prime && rev == i)
      printf("%d ", i);

    /* task 2: count primes */
    /*   prime check (2nd time, identical) */
    is_prime = 1;
    for (d = 2; d * d <= i; d++)
      if (i % d == 0) { is_prime = 0; break; }
    if (is_prime) count++;
  }
  printf("\nPrime count: %d\n", count);

  /* task 3: is n a palindrome? */
  /*   palindrome check (2nd time, identical) */
  t = n; rev = 0;
  while (t > 0) { rev = rev * 10 + t % 10; t = t / 10; }
  if (rev == n)
    printf("%d is a palindrome\n", n);
  else
    printf("%d is not a palindrome\n", n);
  return 0;
}
