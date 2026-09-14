#include <stdio.h>

int main() {
  int arr[1000001] = {0};

  int n;
  scanf("%d", &n);

  int max = -1;
  for (int i = 1; i <= 2 * n - 1; i++) {
    int k;
    scanf("%d", &k);
    if (max < k) {
      max = k;
    }
    arr[k] += 1;
  }

  for (int i = 1; i <= max; i++) {
    if (arr[i] == 1) {
      printf("%d", i);
      break;
    }
  }

  return 0;
}