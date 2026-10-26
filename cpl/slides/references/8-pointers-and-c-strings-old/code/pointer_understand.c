#include <stdio.h>

int main() {
    int arr[3] = {10, 20, 30};
    int *p = arr;  // p 指向 arr[0]

    printf("arr[0] = %d\n", arr[0]);
    printf("*p = %d\n", *p);

    // 指针运算：p 向后移动一个 int 的大小
    p++;

    printf("After p++, *p = %d\n", *p);
    printf("Address of arr[0] = %p\n", (void*)&arr[0]);
    printf("Address stored in p   = %p\n", (void*)p);

    return 0;
}