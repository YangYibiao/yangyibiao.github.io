#include <stdio.h>

int main() {
  printf("%d\n", 1 << 31);
  printf("%u\n", 1u << 31);
  printf("%u\n", 1u << 33);//ub
  printf("%lld\n", 1ll << 31);
  printf("%lld\n", 1ll << 33);
  return 0;
}