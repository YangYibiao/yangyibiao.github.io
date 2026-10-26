#include <stdio.h>

#define LEN 10
int dictionary[LEN] = {1, 1, 5, 5, 5, 5, 5, 5, 9, 10};

int main() {
  int key = 0;
  scanf("%d", &key);

//  int low = 0;
//  int high = LEN - 1;
  int index = -1;
  for (int low = 0, high = LEN - 1; low <= high; ) {
//  while (low <= high) {
    // loop
    int mid = (low + high) / 2;
    if (key == dictionary[mid]) {
      index = mid;
//      break;
      high = mid - 1;
    } else if (key > dictionary[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  if (index == -1) {
    printf("%d is not found\n", key);
  } else {
    printf("The index of %d is %d\n", index, key);
  }
  return 0;
}
