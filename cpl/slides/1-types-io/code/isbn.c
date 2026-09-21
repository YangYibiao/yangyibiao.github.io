/* Computes an ISBN-13 check digit (e.g., the textbook 978-7-04-030276-9) */

#include <stdio.h>

int main(void)
{
  int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12;
  int odd_sum, even_sum, total;

  printf("Enter the first twelve digits of an ISBN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",
        &d1, &d2, &d3, &d4, &d5, &d6, &d7, &d8, &d9, &d10, &d11, &d12);
  odd_sum  = d1 + d3 + d5 + d7 + d9 + d11;
  even_sum = d2 + d4 + d6 + d8 + d10 + d12;
  total = odd_sum + 3 * even_sum;

  printf("Check digit: %d\n", (10 - total % 10) % 10);

  return 0;
}
