/* calc.c: RPN 计算器主程序 —— 只写 main 中的处理
   输入形如 "30 5 - 7 *", 读到 EOF 后输出栈顶结果 (应为 175).
   提示: 用 get_token 逐个读; 数字 push; 运算符 pop 两个操作数, 运算后 push 回去. */
#include <stdio.h>
#include "stack.h"
#include "token.h"

int main(void)
{
  int token;

  while ((token = get_token()) != EOF) {
    /* TODO: 数字入栈; 运算符则弹出两个操作数, 计算后把结果入栈 */
  }

  /* TODO: 打印 pop() 的结果 */

  return 0;
}
