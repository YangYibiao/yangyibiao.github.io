#include <stdio.h>

int main() {
  int number = 0;
  scanf("%d", &number);

  number = number >= 0 ? number : -number;
  int num_of_digits = 0;

  if (number == 0) {
    num_of_digits++;
  } else {
    while (number > 0) {
      number = number / 10;
      num_of_digits++;
    }
  }

  printf("Number of digits is %d\n", num_of_digits);
}
