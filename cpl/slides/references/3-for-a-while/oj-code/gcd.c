#include <stdio.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);

  int min = a < b ? a : b;
  int max = a > b ? a : b;
  while (1) {
    int temp1 = min;
    int temp2 = max % min;
    if (temp2 == 0) {
      printf("%d", min);
      break;
    } else {
      max = temp1;
      min = temp2;
    }
  }
  return 0;
}
