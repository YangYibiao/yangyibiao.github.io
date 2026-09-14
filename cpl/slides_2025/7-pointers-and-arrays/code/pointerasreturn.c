#include <stdio.h>

int *f(void) {
  int i;
  i = 8;
  return &i;
}

int *max(int *a, int *b) {
  if (*a > *b) {
    return a;
  } else {
    return b;
  }
}

int main() {
  int *p, i = 1, j = 2;
  p = max(&i, &j);
  printf("p: %p,\n&a: %p\n&b:\n", p, &i, &j);
  printf("%d\n", *p);

  p = f();
  printf("%p, %d\n", p, *p);
  return 0;
}