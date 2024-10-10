#include <stdio.h>

int main(void) {
  int number;
  scanf("%d", &number);

  // TODO: counting number of digits

  int numb_of_digits = 0;

  do {
    number /= 10;
    numb_of_digits++;
  } while (number > 0);

  printf("Number of digits: %d\n", numb_of_digits);
  return 0;
}