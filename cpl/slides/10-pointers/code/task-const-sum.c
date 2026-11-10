/* task-const-sum.c: 任务 5 —— 只读参数
   任务: 完成 int sum(const int *a, int n), 返回数组元素之和.
   要求: 函数内部不能修改 a[i];
         可以试着写 a[i] = 0; 看编译器报什么错, 然后注释掉.
   测试: {1, 2, 3, 4, 5} -> 15
   提示: const int *a 表示"通过 a 不能修改数组元素".
   在 TODO 处补完函数体. */
#include <stdio.h>

int sum(const int *a, int n)
{
  /* TODO: 累加 a[0]..a[n-1] 并返回 */
  return 0;
}

int main(void)
{
  int a[] = {1, 2, 3, 4, 5};

  printf("sum = %d\n", sum(a, 5));  /* 期望 15 */
  return 0;
}
