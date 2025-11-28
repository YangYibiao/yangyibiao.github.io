#include <stdio.h>

int main() {
  char str[] = "Hello";
  char *p = "Hello";

  str[0] = 'N';
//  p[0] = 'J';

  printf("str: %p\n", str);
  printf("p: %p\n", p);
  printf("&p: %p\n", &p);
  printf("string of str: %s\n", str);
  printf("string of p: %s\n", p);
  return 0;
}