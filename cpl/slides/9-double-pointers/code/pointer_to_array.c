#include <stdio.h>

// 示例 4：指向数组的指针（Array Pointer）
int main() {
  int arr[4] = {10, 20, 30, 40};

  int (*p)[4] = &arr;   // p 是指向含 4 个 int 的数组的指针

  printf("(*p)[2] = %d\n", (*p)[2]); // 访问 arr[2]
  printf("*((*p) + 2) = %d\n", *((*p) + 2));

  return 0;
}
