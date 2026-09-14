#include <stdio.h>

int main() {
  int s[100002];
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    scanf("%d", &s[i]);
  }

  int sum = 0, min_s = 0;
  for (int i = 0; i <= n; i++) {
    if (sum < i) {
      int min = i - sum;
      sum = sum + s[i] + min;
      min_s += min;
    } else {
      sum = sum + s[i];
    }
  }

  printf("%d", min_s);
  return 0;
}