/* Array sum: no functions */
#include <stdio.h>

int fsum(int arr[], int n);

int main(void)
{
  int b[5] = {3, 7, 1, 9, 4};
  int len = sizeof(b) /sizeof(b[0]);
  int sum = fsum(b, 5);
  printf("sum = %d\n", sum);
  return 0;
}

int fsum(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}
