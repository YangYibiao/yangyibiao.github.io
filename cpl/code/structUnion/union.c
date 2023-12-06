#include <stdio.h>

struct
{
  char c;
  int i;
  // char c;
  double d;
  long double e;
} a;

union
{
  int i;
  double d;
} b;

int main()
{
  a.i = 100;
  a.d = 235;
  printf("a.i: %p %d\n", &a.i, a.i);
  printf("%d %d %d\n", sizeof(a), sizeof(a.i), sizeof(a.d));
  printf("a.c: %p %c\n", &a.c, a.c);
  printf("a.d: %p %f\n", &a.d, a.d);
  b.i = 200;
  b.d = 50.2;
  printf("b.i: %p %d\n", &b.i, b.i);
  printf("b.d: %p %f\n", &b.d, b.d);
}