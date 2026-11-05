/* task-mixed-scanf.c: 任务 —— 一次读入混合类型
   任务: 一行输入年龄、身高、性别, 分别读入 int / double / char 并回显:
     输入 (年龄 身高 性别): 19 1.75 M
     age=19 height=1.75 gender=M
   提示:
     - 三个转换说明按顺序匹配: %d → int, %lf → double, %c → char
     - 格式串里 %c 前留一个空格 (" %c"), 可跳过输入中的空白
     - 别忘了变量前加 &
   在 TODO 处补完代码 */
#include <stdio.h>

int main(void)
{
  int age;
  double height;
  char gender;

  /* TODO: 提示并一行读入三个值 (scanf 用 "%d %lf %c") */

  /* TODO: 按样例格式输出 */

  return 0;
}
