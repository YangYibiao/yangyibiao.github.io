/* Game of Life: no functions (evolve one generation) */
#include <stdio.h>

#define SIZE 8

int main(void)
{
  /* extra border of zeros avoids boundary checks */
  int board[SIZE + 2][SIZE + 2] = {{0}};
  int next[SIZE + 2][SIZE + 2] = {{0}};
  int i, j, m, n, cnt;

  /* initial pattern: a glider */
  board[2][3] = 1;
  board[3][4] = 1;
  board[4][2] = 1;
  board[4][3] = 1;
  board[4][4] = 1;

  /* print the initial board */
  for (i = 1; i <= SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
      printf("%c", board[i][j] ? '*' : '.');
    }
    printf("\n");
  }
  printf("\n");

  /* count neighbors + apply rules, all inline */
  for (i = 1; i <= SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
      cnt = -board[i][j];
      for (m = i - 1; m <= i + 1; m++) {
        for (n = j - 1; n <= j + 1; n++) {
          cnt += board[m][n];
        }
      }
      if (board[i][j] == 1) {
        next[i][j] = (cnt == 2 || cnt == 3);
      } else {
        next[i][j] = (cnt == 3);
      }
    }
  }

  /* print the new generation */
  for (i = 1; i <= SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
      printf("%c", next[i][j] ? '*' : '.');
    }
    printf("\n");
  }
  return 0;
}
