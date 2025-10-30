#include <stdio.h>

int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);

  if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) {
    printf("Leap year!\n");
  } else {
    printf("Normal year!\n");
  }

  long long m = n % 400 + k % 400;

  if ((m % 4 == 0 && m % 100 != 0) || (m % 400 == 0)) {
    printf("Leap year!\n");
  } else {
    printf("Normal year!\n");
  }

  return 0;
}
