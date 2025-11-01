#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 10000
#define RANGE 20

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

  // TODO: insertion sort with binary search
  for (int i = 1; i < size; i++) {
    int key = numbers[i];
    // [0 .. i - 1] 是有序的
    int low = 0, high = i - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (key >= numbers[mid]) {
        low = mid + 1;
      } else if (key < numbers[mid]) {
        high = mid - 1;
      }
    }

    for (int j = i - 1; j >= low; j--) {
      numbers[j + 1] = numbers[j];
    }
    numbers[low] = key;
  }

  // print the sorted array
  for (int k = 0; k < size; k++) {
    printf("%d ", numbers[k]);
  }
  printf("\n");

  return 0;
}
