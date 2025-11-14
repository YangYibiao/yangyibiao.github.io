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
  //char c = "ef";//char * c =
  print_binary(a);
  //PrintBinary(c);
  //printf("%d\n", c);

  return 0;
}