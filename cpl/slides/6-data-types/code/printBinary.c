#include<stdio.h>
#include<limits.h>

union {
  int i;
  float f;
} num;

void print(int a) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (a >> i) & 1);
    if (i % 8 == 0)
      printf(" ");
  }
  printf("\n");
}

int main() {
  unsigned char a = 200;
  int b = a;
  printf("%d %d %d\n", a, b, b & 0xff);
  print(b);
  print(b >> 2);
  print(b & 0xf);
  num.f = 1.0 / 0.0;//0.0/0.0
  print(num.i);
  //printf("%d", num.f!=num.f);
  int c = -10000;
  print(c);
  print(c >> 2);
  return 0;
}