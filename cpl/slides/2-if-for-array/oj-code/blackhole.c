#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int sum = 0;
  for (;;) {
    int a = N / 100;
    int b = N / 10 % 10;
    int c = N % 10;

    int max = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    int min = (a < b) ? (a < c ? a : c) : (b < c ? b : c);
    int sec = a + b + c - max - min;

    int max_value = 100 * max + sec * 10 + min;
    int min_value = 100 * min + sec * 10 + max;

    int N_prime = max_value - min_value;
    if (N > N_prime) {
      sum += N - N_prime;
    }

    if (N_prime == 495) {
      break;
    }
    N = N_prime;
  }
  printf("%d", sum);
  return 0;
}
