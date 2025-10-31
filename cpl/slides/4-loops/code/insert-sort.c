// Created by 杨已彪 on 2024/10/18.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 10000
#define RANGE 10

int main(void) {
  int numbers[MAX_LEN] = {0};
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
    int j = i - 1;
    while (j >= 0 && numbers[j] > key) {
      numbers[j + 1] = numbers[j];
      j--;
    }
    numbers[j + 1] = key;

    // numbers[0 .. i] is already sorted
    for (int k = 0; k < size; k++) {
      printf("%d ", numbers[k]);
    }
    printf("\n");
  }

  // print the sorted array
  for (int k = 0; k < size; k++) {
    printf("%d ", numbers[k]);
  }
  printf("\n");

  return 0;
}
