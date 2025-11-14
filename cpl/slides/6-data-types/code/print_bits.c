#include <stdio.h>

void display(int a) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (a >> i) & 1);
    if (i % 8 == 0)
      printf(" ");
  }
  printf("\n");
}

int main() {
  int num = 10000;
  display(num);

  return 0;
}