

#include <stdio.h>

// 示例 5：指向指针的指针 vs. 指向数组的指针
int main() {
  int matrix[2][3] = {{1,2,3}, {4,5,6}};

  int *p1 = matrix[0];     // OK：matrix[0] 是 int*
  int **p2 = (int **) &matrix; // ⚠️ 类型并不等价，仅示例对比用
  int (*p3)[3] = matrix;   // 正确：指向数组的指针

  printf("Using p1: p1[2] = %d\n", p1[2]);
  printf("Using p3: p3[1][2] = %d\n", p3[1][2]);

  return 0;
}
