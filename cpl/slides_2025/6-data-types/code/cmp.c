#include <stdio.h>

void print_binary(int num) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (num >> i) & 0x1);
    if (i % 8 == 0)
      printf(" ");
  }
  printf("\n");
}

int main() {
  int a = 10002;
  print_binary(a);

  char c = a;
  printf("%d", c);
  
  return 0;
}