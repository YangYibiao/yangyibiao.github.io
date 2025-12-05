#include <stdio.h>
#include <stdlib.h>

int main() {
  int (*p)[10] = malloc(100); // p is a pointer to an array of 10 integers
  printf("%p\n", p);
  p++;
  printf("%p\n", p); // ???
}