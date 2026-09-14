#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 10000
#define RANGE 20

int numbers[MAX_LEN] = {0};

int main(void) {
  int size = 0;
  scanf("%d", &size);

  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    numbers[i] = rand() % RANGE;
  }

  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  // TODO: insertion sort
  for (int i = 1; i < size; i++) {
    int key = numbers[i];
    // [0 .. i - 1] 是有序的
    int j = i - 1;
    for (; j >= 0; j--) {
      if (numbers[j] > key) {
        numbers[j + 1] = numbers[j];
      } else {
        break;
      }
    }
    numbers[j + 1] = key;
  }

  // print the sorted array
  for (int k = 0; k < size; k++) {
    printf("%d ", numbers[k]);
  }
  printf("\n");

  return 0;
}
