/* struct-compare.c: 演示结构体能整体赋值、不能整体比较
   运行: cc -std=c11 struct-compare.c && ./a.out
   期望输出: a.number=1 a.name=bolt
             same
   说明: 下面注释掉的 if (a == b) 是编译错误 (GCC: invalid operands to binary '==');
         C 只提供整体赋值, 比较必须逐成员进行. */
#include <stdio.h>
#include <string.h>

struct {
  int number;
  char name[20];
} a, b;

int main(void)
{
  a.number = 1;
  strcpy(a.name, "bolt");

  b = a;                          /* OK: 整体赋值 (数组也一起复制) */
  printf("a.number=%d a.name=%s\n", a.number, a.name);

  /* if (a == b) printf("same\n");   编译错误: 结构体不能用 == 比较 */

  if (a.number == b.number && strcmp(a.name, b.name) == 0) {
    printf("same\n");             /* 正确做法: 逐成员比较 */
  }
  return 0;
}
