#include <stdio.h>

int main(void) {
  int numbers[10] = {1, 1, 3, 5, 8, 13, 21, 35, 56};
  int target;
  scanf("%d", &target);

  int left = 0;
  int right = 9;
  while (left <= right) {
    int middle = (left + right) / 2;
    if (numbers[middle] == target) {
      printf("Found at index %d\n", middle);
      return 0;
    } else if (numbers[middle] < target) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  printf("Not found\n");
  return 0;
}