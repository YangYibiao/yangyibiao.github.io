#include <stdio.h>

#define LEN 10

int bsearch(int dict[], int len, int key);

int main() {
  int dictionary[LEN] = {1, 1, 5, 5,
                         5, 5, 5, 5, 9, 10};

  int key = 0;
  scanf("%d", &key);

  int index = bsearch(dictionary, LEN, key);
  if (index == -1) {
    printf("%d is not found\n", key);
  } else {
    printf("The index of %d is %d\n", index, key);
  }
  return 0;
}

int bsearch(int dict[], int len, int key) {
  int index = -1;
  for (int low = 0, high = len - 1; low <= high;) {
    int mid = (low + high) / 2;
    if (key == dict[mid]) {
      index = mid;
      high = mid - 1;
    } else if (key > dict[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return index;
}