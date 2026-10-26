#include <stdio.h>

int main() {
  int number = 0;
  scanf("%d", &number);

  number = number < 0 ? -number : number;
  int num_of_digits = 1;
  for (; number / 10 != 0; num_of_digits++) {
    number /= 10;
  }
  printf("Number of digits is %d\n", num_of_digits);
  return 0;
}
