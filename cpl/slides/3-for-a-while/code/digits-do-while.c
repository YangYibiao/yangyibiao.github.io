#include <stdio.h>

int main() {
  int number = 0;
  scanf("%d", &number);

  int num_of_digits = 0;
  do {
    number /= 10;
    num_of_digits++;
  } while (number > 0);
  printf("Number of digits is %d\n", num_of_digits);
}
