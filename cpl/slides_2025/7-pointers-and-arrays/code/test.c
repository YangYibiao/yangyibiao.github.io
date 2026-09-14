#include <stdio.h>

int sum(int a[], int n)
{
    printf("%p\n", a);
    int s = 0;
    int *p = a;
    for (; p < a + n; p++) {
        s += *p;
    }
    return s;
}

int main() {
    int arr[5] = {1,2,3,4,5};
    printf("%p\n", arr);
    printf("%d", sum(arr, 5));
}