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

  // TODO: bubbule sort （升序）
  for (int i = 0; i < size - 1; i++) { // 每一轮都会有一个元素有序冒泡到了合适的位置
    int flag = 0;
    for (int j = 0; j < size - 1 - i; j++) {
      if (numbers[j] > numbers[j + 1]) {
        // swap
        int temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
        flag = 1; // 存在变化
      }
    }
    if (flag == 0) {
      break;
    }
  }

  // print the sorted array
  for (int k = 0; k < size; k++) {
    printf("%d ", numbers[k]);
  }
  printf("\n");
  return 0;
}
