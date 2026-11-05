/* token.c: 从标准输入读 RPN 表达式的下一个记号 —— 只写函数体
   返回: 读到一个整数时返回该整数; 读到 + - * / 时返回对应字符; 到 EOF 返回 EOF.
   提示: 跳过空白后, 用 isdigit 判断数字; 若为数字, 循环读入后续数字字符并算出整数值. */
#include <ctype.h>
#include <stdio.h>
#include "token.h"

int get_token(void)
{
  /* TODO: 跳过空白; 读整数或运算符; 到 EOF 返回 EOF */
  return EOF;
}
