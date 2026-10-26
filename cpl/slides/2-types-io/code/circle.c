//
// Created by 杨已彪 on 2024/9/26.
//
#include <stdio.h>

int main(void) {
  const double PI = 3.14159;
  int radius = 10;
  double circumference = 2 * PI * radius;
  double area = PI * radius * radius;

  // %d: decimal
  // .2: precision
  printf("radius = %d\ncircumference = %.2f\narea = %.2f\n", radius, circumference, area);
  return 0;
}