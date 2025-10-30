#include <stdio.h>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  if (a + b <= c || a + c <= b || b + c <= a) {
    printf("not triangle");
  } else if (a == b && b == c) {
    printf("equilateral triangle");
  } else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
    printf("right triangle");
  } else {
    if (a * a + b * b < c * c || a * a + c * c < b * b || b * b + c * c < a * a) {
      printf("obtuse");
    } else {
      printf("acute");
    }
    if (a == b || b == c || a == c) {
      printf(" isosceles");
    }
    printf(" triangle");
  }
  return 0;
}
