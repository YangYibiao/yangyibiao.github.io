/* Selection sort: no functions */
#include <stdio.h>

void sorting(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    int t = arr[i]; arr[i] = arr[min]; arr[min] = t;
  }
}

int main(void)
{
  int a[10], n = 10, i, j;

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  sorting(a, 15);
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
