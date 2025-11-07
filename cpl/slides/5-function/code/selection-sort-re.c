#include <stdio.h>

#define LEN 1000

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int arr[], int len) {
  //sorting
  for (int i = 0; i < len; i++) {
    // selecting i..len-1 the smallest one
    int min_value = arr[i];
    int min_index = i;
    for (int j = i; j < len; j++) {
      if (arr[j] < min_value) {
        min_index = j;
        min_value = arr[j];
      }
    }

    // min_index  swap i
    swap(&arr[i], &arr[min_index]);
    // int temp = arr[i];
    // arr[i] = arr[min_index];
    // arr[min_index] = temp;
  }
}

int main() {
  int len = -1;
  int numbers[LEN];

  // (1) 没有输入流 -1（EOF）
  // (2) 读到数据返回1 (linux下按Ctrl + D）
  while (scanf("%d", &numbers[++len]) != EOF);

  printf("Len of numbers is: %d\n", len);

  printf("Before sorting: \n");
  for (int i = 0; i < len; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");

  selection_sort(numbers, len);

  printf("After sorting: \n");
  for (int i = 0; i < len; i++) {
    printf("%d ", numbers[i]);
  }
  printf("\n");
  return 0;
}