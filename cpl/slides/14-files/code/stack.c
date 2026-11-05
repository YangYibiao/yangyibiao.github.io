/* stack.c: 栈的实现 —— 只写函数体
   1. make_empty: 清空栈
   2. is_empty: 栈空返回 1, 否则返回 0
   3. is_full: 栈满返回 1, 否则返回 0
   4. push: 入栈; 栈满时报告错误
   5. pop: 出栈并返回栈顶元素; 栈空时报告错误
   提示: contents/top 用文件作用域的 static 变量, 只在本文件可见. */
#include <stdio.h>
#include "stack.h"

static int contents[STACK_SIZE];
static int top = 0;

void make_empty(void)
{
  /* TODO: top = 0 */
}

int is_empty(void)
{
  /* TODO: 返回 top == 0 */
  return 1;
}

int is_full(void)
{
  /* TODO: 返回 top == STACK_SIZE */
  return 0;
}

void push(int i)
{
  /* TODO: 栈满则报告错误; 否则 contents[top++] = i */
}

int pop(void)
{
  /* TODO: 栈空则报告错误; 否则返回 contents[--top] */
  return 0;
}
