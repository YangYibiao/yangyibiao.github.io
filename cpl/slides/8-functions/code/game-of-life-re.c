/* Game of Life: no functions (evolve one generation) */
#include <stdio.h>

#define SIZE 8

void print_matrix(int mat[][SIZE + 2], int rows) {
  /* print the initial board */
  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= SIZE; j++) {
      printf("%c", mat[i][j] ? '*' : '.');
    }
    printf("\n");
  }
  printf("\n");
}

void next_gen(int mat[][SIZE + 2], int next[][SIZE + 2], int rows) {
  /* count neighbors + apply rules, all inline */
  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j <= SIZE; j++) {
      int cnt = -mat[i][j];
      for (int m = i - 1; m <= i + 1; m++) {
        for (int n = j - 1; n <= j + 1; n++) {
          cnt += mat[m][n];
        }
      }
      if (mat[i][j] == 1) {
        next[i][j] = (cnt == 2 || cnt == 3);
      } else {
        next[i][j] = (cnt == 3);
      }
    }
  }
}

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

  print_matrix(board, SIZE + 2);
  next_gen(board, next, SIZE + 2);
  print_matrix(next, SIZE + 2);
  return 0;
}
