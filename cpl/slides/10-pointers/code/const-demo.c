/* const-demo.c: const int * 与 int * const 的合法操作
   运行结果:
     *p = 1
     *p = 2
     i = 4, *q = 4
   说明:
     const int *p: p 可以改指向, *p 不能改
     int * const q: q 不能改指向, *q 可以改 */
#include <stdio.h>

int *f(void) {
  int i = 9; 
  printf("address of i: %p\n", &i);
  return &i; 
}

int main(void)
{
    int i = 1, j = 2;
    int *p = f();
    printf("p = %p, *p = %d\n", p, *p);  /* 2 */

    // const int *p = &i;        /* *p 只读; p 可以改指向 */
    // // *p = 3;
    // printf("*p = %d\n", *p);  /* 1 */
    // p = &j;                   /* 合法: 改 p 的指向 */
    // printf("*p = %d\n", *p);  /* 2 */

    int * const q = &i;       /* q 只读; *q 可以改 */
    // q = &j;
    *q = 4;                   /* 合法: 改 i */
    printf("i = %d, *q = %d\n", i, *q);  /* 4 4 */

    return 0;
}
