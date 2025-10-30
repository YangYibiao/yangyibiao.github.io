#include <stdio.h>

int main() {
  long a, b;
  scanf("%ld%ld", &a, &b);

  printf("%ld\n%ld\n%ld\n", a & b, a | b, a ^ b);
  printf("%ld\n%ld\n%ld\n", ~a, a << b, a >> b);
  printf("%ld\n", (a >> b) % 2);
  int s = 0;
  for (int i = 0; i < 32; i++) {
    s += (a >> i) % 2;
  }
  printf("%ld\n", s);

  return 0;
}
