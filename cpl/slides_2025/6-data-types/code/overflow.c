#include <stdio.h>

int main() {
  int a = 0;

  while (++a > 0);
  printf("max int: %d\n", a);
  printf("max int: %d\n", a - 1);
  /*
   int b = -1;
   char c = -1;
   printf("%u, %u\n", b, c);*/
  return 0;
}