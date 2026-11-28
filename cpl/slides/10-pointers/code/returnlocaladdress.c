#include <stdio.h>

int *f(void) { 
  int i = 8; 
  return &i; 
}

int main() {
  int *p = f();
  int a[2000] = {0};
  printf("%d", *p);
}