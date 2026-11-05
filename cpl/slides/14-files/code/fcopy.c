/* fcopy.c: 把源文件复制到目标文件 (二进制安全)
   任务:
     1. 命令行给出源文件和目标文件两个参数
     2. 用 "rb" 打开源文件, 用 "wb" 打开目标文件
     3. 逐个字符读, 直到 EOF, 依次写入目标文件
   提示: fgetc 返回 int, 用 EOF 判断结束; 两个文件都要 fclose. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  /* TODO: 检查 argc 是否为 3 */
  /* TODO: 以 "rb" 打开 argv[1], 以 "wb" 打开 argv[2], 都判 NULL */
  /* TODO: 循环 fgetc/fputc 复制, 直到 EOF */
  /* TODO: 关闭两个文件 */
  return 0;
}
