/* use-after-free.c: free 后不置 NULL, 继续使用 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof(int));
    if (p == NULL) return 1;

    *p = 42;
    printf("*p = %d\n", *p);

    free(p);
    /* p = NULL; 忘记 */

    printf("p after free = %p\n", (void *)p);
    printf("*p after free = %d\n", *p);   /* use-after-free */
    return 0;
}
