/* canopen.c: 判断命令行参数给出的文件能否打开
   任务:
     1. 参数个数不为 2 时, 打印用法并退出
     2. 用 fopen 以 "r" 模式打开 argv[1]
     3. 打开成功打印 "<文件名> 可以打开", 失败打印 "<文件名> 打不开"
   提示: fopen 失败返回 NULL; 文件用完要 fclose. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  /* TODO: 检查 argc 是否为 2 */
  /* TODO: 打开 argv[1], 判断返回值是否为 NULL */
  /* TODO: 按结果打印提示, 关闭文件 */
  return 0;
}
