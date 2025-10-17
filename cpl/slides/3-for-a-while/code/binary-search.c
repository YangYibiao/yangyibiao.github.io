#include <stdio.h>

#define LEN 10
int dictionary[LEN] = {1, 1, 3, 4, 5, 6, 7, 8, 9, 10};
int main() {
  int key = 0;
  scanf("%d", &key);

  int index = -1;
  int low = 0;
  int high = LEN - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (dictionary[mid] == key) {
      index = mid;
//      break;
      high = mid - 1;
    } else {
      if (dictionary[mid] < key) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }

  if (index != -1) {
    printf("The index of %d is %d\n", index, key);
  } else {
    printf("Not found\n");
  }
  return 0;
}
