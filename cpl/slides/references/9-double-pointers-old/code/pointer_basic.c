#include <stdio.h>

// 示例 1：一级指针访问数组元素
int main() {
  int arr[5] = {10, 20, 30, 40, 50};
  int *p = arr;        // 等价于 &arr[0]

  printf("arr[2] = %d\n", arr[2]);
  printf("*(p + 2) = %d\n", *(p + 2));   // 指针解引用访问数组

  p++; // 指针移动到第二个元素
  printf("After p++, *(p) = %d\n", *p);

  return 0;
}
