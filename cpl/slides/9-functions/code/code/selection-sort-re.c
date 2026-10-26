#include <stdio.h>

//   printArr(numbers, 10);
void printArr(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
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
   int temp = arr[i];
   arr[i] = arr[min_index];
   arr[min_index] = temp;
  }
}

int main() {
  int numbers[10] = {3, 5, 6, 0,
                      2, 7, 8, 8,
                      9, 10};

//  for (int i = 0; i < 10; i++) {
//    printf("address of %d: %p\n", i, &numbers[i]);
//  }
  printf("Before sorting: \n");
  printArr(numbers, 10);

  selection_sort(numbers, 10);

  printf("After sorting: \n");
  printArr(numbers, 10);
  return 0;
}