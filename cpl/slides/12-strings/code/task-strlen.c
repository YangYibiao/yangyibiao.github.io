/* task-strlen.c: 任务 —— 自己实现 strlen
   任务: 写 int my_strlen(const char *s), 返回字符串长度 (不含结尾的 '\0');
         分别用下标版和指针版实现, 在 main 中验证
   样例:
     "abc" 的长度 = 3
     "" 的长度 = 0
     "hello world" 的长度 = 11
   提示:
     - 下标版: 从 s[0] 数到 s[i] == '\0' 为止
     - 指针版: *s 非零就计数并 s++, 循环结束时走过的步数就是长度
     - 不要调用 <string.h> 的 strlen, 自己数
   在 TODO 处补完两个函数 */
#include <stdio.h>

int my_strlen_index(const char *s)
{
  /* TODO: 用下标从 0 开始数, 直到 s[i] == '\0' */
  return 0;
}

int my_strlen_pointer(const char *s)
{
  /* TODO: 用指针 *s 判断, 每走一步计数一次 */
  return 0;
}

int main(void)
{
  const char *tests[] = {"abc", "", "hello world"};

  for (int i = 0; i < 3; i++) {
    printf("\"%s\" 的长度 = %d (下标版) / %d (指针版)\n",
           tests[i], my_strlen_index(tests[i]), my_strlen_pointer(tests[i]));
  }
  return 0;
}
