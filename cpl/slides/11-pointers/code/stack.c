#define N 100
int contents[N];
int top = 0;

int *top_ptr = contents;

void push(int i) {
  if (top_ptr < contents + N) {
    *(top_ptr++) = i;
  } else {
    printf("stack is full");
  }
  // *top_ptr = i;
  // top_ptr = top_ptr + 1;
}

int pop(void) {
  if (top_ptr > contents) {
    return *--top_ptr;
  } else {
    printf("stack is empty");
  }
  // top_ptr = top_ptr - 1;
  // *top_ptr;
}

void push_index(int i) {
  if (top < N) {
    contents[top] = i; 
    top = top + 1;
  } else {
    printf("stack is full");
  }
}

int pop_index(void) {
  if (top >= 1) {
    top = top - 1;
    return contents[top]; 
  } else {
    printf("stack is empty");
  }
}