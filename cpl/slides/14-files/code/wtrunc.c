/* wtrunc.c: 演示 "w" 模式打开文件会立即清空原有内容
   运行: 先准备一个内容非空的 grades.txt, 再
         cc -std=c11 wtrunc.c && ./a.out
   现象: grades.txt 只剩 "new line", 原来的成绩全部消失.
   提示: 想保留原内容并追加, 应使用 "a" 模式. */
#include <stdio.h>

int main(void)
{
  FILE *fp = fopen("grades.txt", "w");  /* 打开瞬间, 旧内容没了! */

  if (fp == NULL) {
    return 1;
  }
  fprintf(fp, "new line\n");
  fclose(fp);
  return 0;
}
