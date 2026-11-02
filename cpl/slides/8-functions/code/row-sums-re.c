/* Row sums: no functions */
#include <stdio.h>

int main(void)
{
  int scores[5][3] = {{80, 85, 90}, {70, 75, 80}, {90, 92, 88},
                      {60, 65, 70}, {85, 80, 90}};
  int sums[5];
  int i, j;

  for (i = 0; i < 5; i++) {
    sums[i] = 0;
    for (j = 0; j < 3; j++) {
      sums[i] += scores[i][j];
    }
  }

  for (i = 0; i < 5; i++) {
    printf("student %d total: %d\n", i + 1, sums[i]);
  }
  return 0;
}
