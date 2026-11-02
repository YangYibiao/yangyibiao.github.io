/* Game of Life: with functions (one thing per function) */
#include <stdio.h>

#define SIZE 8

int count_neighbors(int board[][SIZE + 2], int i, int j)
{
  int cnt = -board[i][j], m, n;

  for (m = i - 1; m <= i + 1; m++) {
    for (n = j - 1; n <= j + 1; n++) {
      cnt += board[m][n];
    }
  }
  return cnt;
}

void next_generation(int board[][SIZE + 2])
{
  int new_board[SIZE + 2][SIZE + 2] = {{0}};
  int i, j, cnt;

  for (i = 1; i <= SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
      cnt = count_neighbors(board, i, j);
      if (board[i][j] == 1) {
        new_board[i][j] = (cnt == 2 || cnt == 3);
      } else {
        new_board[i][j] = (cnt == 3);
      }
    }
  }

  /* write back */
  for (i = 1; i <= SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
      board[i][j] = new_board[i][j];
    }
  }
}

void print_board(int board[][SIZE + 2])
{
  int i, j;

  for (i = 1; i <= SIZE; i++) {
    for (j = 1; j <= SIZE; j++) {
      printf("%c", board[i][j] ? '*' : '.');
    }
    printf("\n");
  }
}

int main(void)
{
  int board[SIZE + 2][SIZE + 2] = {{0}};
  int i;

  /* initial pattern: a glider */
  board[2][3] = 1;
  board[3][4] = 1;
  board[4][2] = 1;
  board[4][3] = 1;
  board[4][4] = 1;

  for (i = 0; i < 10; i++) {
    print_board(board);
    next_generation(board);
  }
  return 0;
}
