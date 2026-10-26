#include <stdio.h>

int main() {
  int x = -1;
  unsigned u = 2147483648; // 2^31
  printf("x (int -1) = %u (u) = %d (d) \n", x, x);
  printf("u (unsigned 2^31) = %u (u) = %d (d) \n", u, u);
  return 0;
}
