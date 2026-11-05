/* task-newline.c: 任务 —— 遗留换行的坑
   任务:
     1) 先读入年龄 (整数), 再读入性别 (字符), 运行看看性别读到了什么
     2) 修复它, 让性别能正确读入
   样例:
     输入: 19 M        (19 和 M 之间一个空格)
     期望输出: age=19 gender=M
     错误版本的实际输出: age=19 gender= (读到了换行, 打印为空)
   提示:
     - scanf("%d") 读完数字后, 输入缓冲区里还剩一个换行 '\n'
     - 在 %c 前加一个空格: scanf(" %c", &gender) —— 会先跳过空白
   在 TODO 处补完代码 (先写错误版观察, 再改成正确版) */
#include <stdio.h>

int main(void)
{
  int age;
  char gender;

  /* TODO: 读入 age, 再读入 gender (先按错误写法 scanf("%c") 观察) */

  /* TODO: 改成 scanf(" %c", &gender) 修复, 再验证 */

  printf("age=%d gender=%c\n", age, gender);
  return 0;
}
