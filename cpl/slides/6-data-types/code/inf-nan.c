#include <stdio.h>

int main() {
  printf("%f\n", 123.0 / 0.0);
  printf("%f\n", -123.0 / 0.0);
  printf("%f\n", 0.0 / 0.0);
  //int a  = (int)10.2;
  //printf("%d\n", a);

  int a = -10;
  unsigned int b = 10;
  if (-10 < 10) {
    printf("a < b\n");
  } else {
    printf("b < a\n");
  }
  return 0;
}