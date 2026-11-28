/* task-stack.c: 课堂编码 —— 补全栈的 push/pop
   任务: 补全 push 和 pop 中的两条语句, 用 * 与 ++/-- 实现栈.
   期望输出:
     pop = 9
     pop = 8
     pop = 10
     pop = 7
   提示: push 用 *top_ptr++ (先存再后移); pop 用 *--top_ptr (先回退再取).
   在 TODO 处补完. */
#include <stdio.h>

#define N 5

int contents[N];
int *top_ptr = contents;

void push(int i)
{
    if (top_ptr == contents + N) {
        printf("栈满\n");
        return;
    }
    /* TODO: 用 *top_ptr++ 把 i 存入当前空位, 再后移 */
    // *top_ptr = i;
    // top_ptr = top_ptr + 1;
    *top_ptr++ = i;
}

int pop(void)
{
    if (top_ptr == contents) {
        printf("栈空\n");
        return -1;
    }
    /* TODO: 用 *--top_ptr 先回退, 再返回该位置的值 */
    // top_ptr = top_ptr - 1;
    // return *top_ptr;
    return *--top_ptr;
}

int main(void)
{
    push(7);
    push(8);
    push(9);
    printf("pop = %d\n", pop());
    printf("pop = %d\n", pop());
    push(10);
    printf("pop = %d\n", pop());
    printf("pop = %d\n", pop());
    return 0;
}
