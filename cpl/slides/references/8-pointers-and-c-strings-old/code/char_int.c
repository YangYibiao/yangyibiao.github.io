#include <stdio.h>
#include <stdlib.h>

void display_bits(int n, int len);

void display_bits_ll(long long n, int len);

int main() {
//  char pc[8] = {'A', 'A', 0, 0, 'A', 0, 0, 0};
  char *pc;
  pc = (char *) malloc(8 * sizeof(char)); // char *p = (char *) malloc(n * sizeof(char));
  *pc = 65;
  *(pc + 1) = 65;
  *(pc + 2) = 0;
  *(pc + 3) = 0;

  *(pc + 4) = 65;
  *(pc + 5) = 0;
  *(pc + 6) = 0;
  *(pc + 7) = 0;

  printf("string of pc: %s\n", pc);

  printf("address of char:\npc:     %p\n", pc);
  printf("pc + 1: %p\n", pc + 1);

  for (int i = 0; i < 8; i++) {
    printf("%d ", *(pc + i));
  }
  printf("\n");

  display_bits(*pc, 8);
  display_bits(*(pc + 1), 8);
  display_bits(*(pc + 2), 8);
  display_bits(*(pc + 3), 8);
  display_bits(*(pc + 4), 8);
  display_bits(*(pc + 5), 8);
  display_bits(*(pc + 6), 8);
  display_bits(*(pc + 7), 8);

  int *pi;
  pi = (int *) pc;
  printf("address of int: \npi:     %p\n", pi);     // 65 * 2^8 + 65
  printf("pi + 1: %p\n", pi + 1); // 65

  printf("%d\n", *pi);
  display_bits(*pi, 32);
  printf("%d\n", *(pi + 1));
  display_bits(*(pi + 1), 32);

  *pi = 1;
  *(pi + 1) = 1;

  for (int i = 0; i < 8; i++) {
    printf("%d ", *(pc + i));
  }
  printf("\n");

  long long *pl;
  pl = (long long *) pc;
  printf("address of long long: \npl: %p\n", pl);
  display_bits_ll(*pl, 64);
  printf("%lld\n", *pl);        // 65 * 2^32 + 65 * 2^8 + 65

  free(pc);
  return 0;
}

void display_bits(int n, int len) {
  for (int i = len - 1; i >= 0; i--) {
    printf("%d", (n >> i) & 1);
    if (i % 8 == 0)
      printf(" ");
  }
  printf("\n");
}

void display_bits_ll(long long n, int len) {
  for (int i = len - 1; i >= 0; i--) {
    printf("%d", (n >> i) & 1);
    if (i % 8 == 0)
      printf(" ");
  }
  printf("\n");
}