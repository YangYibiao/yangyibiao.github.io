#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100 /* maximum number of values on the stack */
 
/* external variables */
int contents[STACK_SIZE];
int top = 0;

void stack_overflow()
{
  printf("Stack overflow\n");
  exit(1);
}

void stack_underflow()
{
  printf("Stack underflow\n");
  exit(1);
}

void make_empty(void)
{
  top = 0;
}
 
int is_empty(void)
{
  return top == 0;
}
int  is_full(void)
{
  return top == STACK_SIZE;
}

void push(int i)
{
  if (is_full())
    stack_overflow();
  else
    contents[top++] = i;
}
 
int pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];
}

int main(){
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  push(6);
  printf("%d\n", pop());
  printf("%d\n", pop());
  printf("%d\n", pop());
  return 0;
}