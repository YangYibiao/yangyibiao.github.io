#include <stdio.h>

int main(void) {
  int max;
  scanf("%d", &max);

  for (int number = 2; number <= max; number++) {
    int is_prime = 1;
    for (int divisor = 2; divisor < number; divisor++) {
      if (number % divisor == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      printf("%d is a prime number.\n", number);
    }
  }
  return 0;
}
// 114514