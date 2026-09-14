#include <stdio.h>

#define N 5

int sum1(int a[], int len) {
  printf("sum1: ");
  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum += a[i];
    printf("%p ", &a[i]);
  }
  printf("\n");
  return sum;
}

int sum2(int *p, int len) {
  printf("sum2: ");
  int sum = 0;
  for (int *q = p; q < p + len; q++) {
    sum += *q;
    printf("%p ", q);
  }
  printf("\n");
  return sum;
}

int sum3(int *p, int len) {
  printf("sum2: ");
  int sum = 0;
  for (int i = 0; i < len; i++) {
    sum += p[i];
    printf("%p ", &p[i]);
  }
  printf("\n");
  return sum;
}

int main(void) {
  int b[N] = {1, 4, 6, 2, 2};

  int *p, sum = 0;
  for (p = &b[0]; p < &b[N]; p++) {
    sum += *p;
  }

  printf("%d\n", sum);

  sum1(b, N);
  sum2(b, N);
  sum3(b, N);
  return 0;
}