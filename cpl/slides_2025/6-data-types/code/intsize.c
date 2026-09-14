#include <stdio.h>

int main() {
  signed short int a = 32767;
  char c = 10000;//00100111 00010000
  printf("%hd\n", a + 1);

  printf("%d\n", c);
  return 0;
}