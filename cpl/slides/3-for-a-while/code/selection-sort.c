#include <stdio.h>

#define LEN 10

int arr[LEN] = {29, 72, 94, 13, 87, 84, 82, 57, 73, 14};
int main() {

  printf("Before sorting: \n");
  for (int i = 0; i < LEN; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  for (int i = 0; i < LEN - 1; i++) {
    int min_index = i;
    int min_value = arr[i];
    for (int j = i + 1; j <= LEN - 1; j++) {
      if (arr[j] < min_value) {
        min_index = j;
        min_value = arr[j];
      }
    }
    printf("Iteration: %d, minimal value is %d(%d)\n", i, arr[min_index], min_index);
    if (min_index != i) {
      int temp = arr[i];
      arr[i] = arr[min_index];
      arr[min_index] = temp;
    }
  }

  printf("After sorting: \n");
  for (int i = 0; i < LEN; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
