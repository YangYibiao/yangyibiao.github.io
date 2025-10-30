#include <stdio.h>

int main() {
  unsigned int a, b;
  scanf("%u%u", &a, &b);

  int mod = 16 * 16;
  int w78 = b % mod;
  b /= mod;
  int w56 = b % mod;
  b /= mod;
  int w34 = b % mod;
  b /= mod;
  int w12 = b % mod;
  printf("%.8p:  %.2lx %.2lx %.2lx %.2lx\n", a, w12, w34, w56, w78);
  return 0;
}
