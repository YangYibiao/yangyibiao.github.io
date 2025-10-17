#include <stdio.h>

int main() {
  int max;
  scanf("%d", &max);

  int count = 0;
  for (int i = 2; i < max; i++) {
    // decide if i is a prime
    int prime = 1;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        prime = 0;
        break;
      }
    }
    if (prime == 1) {
//      printf("%d ", i);
      count++;
    }
  }
  printf("\btotal count: %d", count);
  return 0;
}
