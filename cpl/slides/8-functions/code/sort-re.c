/* Selection sort: with functions */
#include <stdio.h>

void sort(int a[], int n)
{
  int i, j;

  for (i = 0; i < n - 1; i++) {
    int min = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    int t = a[i];
    a[i] = a[min];
    a[min] = t;
  }
}

int main(void)
{
  int a[10], i;

  for (i = 0; i < 10; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, 10);
  for (i = 0; i < 10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
