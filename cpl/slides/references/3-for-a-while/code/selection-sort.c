#include <stdio.h>

#define LEN 1000
int numbers[LEN];

int main() {
  int len = -1;
  // (1) 没有输入流 -1（EOF）
  // (2) 读到数据返回1
  while (scanf("%d", &numbers[++len]) != EOF);

  printf("Len of numbers is: %d\n", len);

  printf("Before sorting: \n");
  for (int i = 0; i < len; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  //sorting
  for (int i = 0; i < len; i++) {
    // selecting i..len-1 the smallest one
    int min_value = numbers[i];
    int min_index = i;
    for (int j = i; j < len; j++) {
      if (numbers[j] < min_value) {
        min_index = j;
        min_value = numbers[j];
      }
    }
    // min_index  swap i
    int temp = numbers[i];
    numbers[i] = numbers[min_index];
    numbers[min_index] = temp;
  }

  printf("After sorting: \n");
  for (int i = 0; i < len; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
  return 0;
}
