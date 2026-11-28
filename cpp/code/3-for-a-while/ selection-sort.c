#include <stdio.h>

#define LEN 20
int numbers[LEN] = {0};

int main(void) {
  int len = -1;
  while (scanf("%d", &numbers[++len]) != EOF);

  for (int i = 0; i < len; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  for (int i = 0; i < len; i++) {
    int min = numbers[i];
    int min_index = i;
    for (int j = i + 1; j < len; ++j) {
      if (numbers[j] < min) {
        min = numbers[j];
        min_index = j;
      }
    }
    int temp = numbers[min_index];
    numbers[min_index] = numbers[i];
    numbers[i] = temp;
  }

  for (int i = 0; i < len; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  return 0;
}