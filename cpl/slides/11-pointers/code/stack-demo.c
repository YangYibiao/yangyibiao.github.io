/* stack-demo.c: 现场演示 —— 用 * 和 ++/-- 实现栈 */
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
    *top_ptr++ = i;
}

int pop(void)
{
    if (top_ptr == contents) {
        printf("栈空\n");
        return -1;
    }
    return *--top_ptr;
}

int main(void)
{
    push(7);
    push(8);
    push(9);
    push(10);
    push(11);
    push(12);
    printf("pop = %d\n", pop());
    printf("pop = %d\n", pop());
    push(10);
    printf("pop = %d\n", pop());
    printf("pop = %d\n", pop());
    printf("pop = %d\n", pop());
    return 0;
}
