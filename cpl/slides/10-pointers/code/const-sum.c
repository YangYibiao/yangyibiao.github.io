/* const-sum.c: const int * 只读参数
   运行结果: sum = 15
   说明: sum 内部不能修改 a[i];
         试着取消注释 a[i] = 0, 编译器会报 read-only variable is not assignable. */
#include <stdio.h>

int sum(const int *a, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        /* a[i] = 0;  // 错误: a[i] 只读 */
    }
    return s;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    printf("sum = %d\n", sum(a, 5));  /* 15 */
    return 0;
}
