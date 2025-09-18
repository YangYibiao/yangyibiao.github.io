#include <stdio.h>

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
  int big, small, b[10], N;

  printf("Enter the number of elements: ");
  scanf("%d", &N);
  printf("Enter %d integers: ", N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &b[i]);
  }

  max_min(b, N, &big, &small);
  return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
  *max = *min = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > *max) {
      *max = a[i];
    } else if (a[i] < *min) {
      *min = a[i];
    }
  }
  printf("Largest: %d\n", *max);
  printf("Smallest: %d\n", *min);
  return;
}