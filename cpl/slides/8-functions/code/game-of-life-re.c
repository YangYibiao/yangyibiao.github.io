/* 演化一代: 数邻居 + 套规则 + 打印, 全在 main 里 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 50

void print_matrix(int arr[][COLS+2]) {
  for (int i = 1; i <= ROWS; i++) {
    for (int j = 1; j <= COLS; j++) {
      printf("%c", arr[i][j] ? '#': '.');
    }
    printf("\n");
  }
  printf("\n");
}

void next_generation(int mat[][COLS+2]) {
  int next[ROWS + 2][COLS + 2] = {0};
  for (int i = 1; i <= ROWS; i++) {
    for (int j = 1; j <= COLS; j++) {
      int cnt = 0;
      for (int m = i - 1; m <= i + 1; m++) {
        for (int n = j - 1; n <= j + 1; n++) {
          cnt += mat[m][n];
        }
      }
      cnt -= mat[i][j];
      if (mat[i][j] == 1) {
        next[i][j] = (cnt == 2 || cnt == 3);
      } else {
        next[i][j] = (cnt == 3);
      }
    }
  }
  for (int i = 1; i <= ROWS; i++) {
    for (int j = 1; j <= COLS; j++) {
      mat[i][j] = next[i][j];
    }
  }
}

int main(void)
{
  int board[ROWS + 2][COLS + 2] = {{0}};
  /* 初始: 一个滑翔机 (初始画面见右栏) */
  board[2][3] = 1;  board[3][4] = 1;
  board[4][2] = 1;  board[4][3] = 1;  board[4][4] = 1;

  {
    int x = 5;
  }
  printf("%d", x);
  print_matrix(board);
  for (int i = 0; i < 50; i++) {
    next_generation(board);
    print_matrix(board);
    sleep(1);
    system("clear");
  }

  return 0;
}
