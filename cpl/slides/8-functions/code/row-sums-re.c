/* Row sums: with functions */
#include <stdio.h>

void row_sums(int scores[][3], int n, int sums[])
{
  int i, j;

  for (i = 0; i < n; i++) {
    sums[i] = 0;
    for (j = 0; j < 3; j++) {
      sums[i] += scores[i][j];
    }
  }
}

int main(void)
{
  int scores[5][3] = {{80, 85, 90}, {70, 75, 80}, {90, 92, 88},
                      {60, 65, 70}, {85, 80, 90}};
  int totals[5];
  int i;

  row_sums(scores, 5, totals);
  for (i = 0; i < 5; i++) {
    printf("student %d total: %d\n", i + 1, totals[i]);
  }
  return 0;
}
