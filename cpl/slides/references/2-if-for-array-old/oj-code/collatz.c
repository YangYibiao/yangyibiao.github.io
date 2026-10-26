#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int step = 0;
  int max = n;
  for (int i = n; i != 1; ) {
    if (i % 2 == 0) {
      i = i / 2;
    } else {
      i = 3 * i + 1;
    }
    if (max < i) {
      max = i;
    }
    step++;
  }
  printf("%d %d", step, max);
  return 0;
}
