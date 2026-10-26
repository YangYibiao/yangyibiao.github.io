#include <stdio.h>
#include <math.h>

int main() {
  int N;
  scanf("%d", &N);


  int M = 0;
  for (int i = N; i > 0; i = i / 10) {
    M++;
  }

  int sum = 0;
  for (int i = N; i > 0; i = i / 10) {
    sum += pow(i % 10, M);
  }

  if (sum == N) {
    printf("%d", M);
  } else {
    printf("0");
  };

  return 0;
}
