/* skeleton.c: 文件操作课堂编码 —— 只写三个函数体
   1. count_lines: 用 fgetc 统计文件中的 '\n' 个数; 打不开返回 -1
   2. print_numbered: 用 fgets 逐行读文件, 打印 "行号 内容"
   3. sum_ints: 用 fscanf 读文件中的所有整数并求和 (挑战)
   提示: 用读取函数的返回值判断循环是否结束, 不要用 while (!feof(fp)). */
#include <stdio.h>
#include <stdlib.h>

int count_lines(const char *filename)
{
  /* TODO: fopen "r", 判 NULL; 循环 fgetc 数 '\n'; fclose; 返回行数 */
  return 0;
}

void print_numbered(const char *filename)
{
  /* TODO: fopen "r", 判 NULL; fgets 逐行读, 打印行号和内容 */
}

int sum_ints(const char *filename)
{
  /* TODO (挑战): fopen "r", 判 NULL; fscanf 读整数直到 EOF, 返回总和 */
  return 0;
}

int main(void)
{
  printf("%d\n", count_lines("skeleton.c"));  /* 期望: 文件的行数 */
  print_numbered("skeleton.c");                /* 期望: 每行前带行号 */
  printf("%d\n", sum_ints("numbers.txt"));     /* 期望: 各整数之和 */
  return 0;
}
