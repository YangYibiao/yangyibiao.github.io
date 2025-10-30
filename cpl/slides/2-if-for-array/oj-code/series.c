#include <stdio.h>
#include <math.h>

int main() {
  double x;
  int n;
  scanf("%lf%d", &x, &n);

  double cur = x;
  double sum = cur;
  for (int i = 1; i <= n; i++) {
    cur = cur * x * x;
    if (i % 2 == 0) {
      sum += cur / (2 * i + 1);
    } else {
      sum -= cur / (2 * i + 1);
    }
  }
  sum *= 4;
  printf("%.10lf", sum);
  return 0;
}
