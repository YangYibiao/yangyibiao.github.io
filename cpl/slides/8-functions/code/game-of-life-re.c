/* 演化一代: 数邻居 + 套规则 + 打印, 全在 main 里 */
#include <stdio.h>
#define SIZE 8

int main(void)
{
  int board[SIZE + 2][SIZE + 2] = {{0}};
  int next[SIZE + 2][SIZE + 2] = {{0}};
  /* 初始: 一个滑翔机 (初始画面见右栏) */
  board[2][3] = 1;  board[3][4] = 1;
  board[4][2] = 1;  board[4][3] = 1;  board[4][4] = 1;

  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j <= SIZE; j++) {
      int cnt = -board[i][j];
      for (int m = i - 1; m <= i + 1; m++) {
        for (int n = j - 1; n <= j + 1; n++) {
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

  for (int i = 1; i <= SIZE; i++) {    /* 打印新一代 */
    for (int j = 1; j <= SIZE; j++) {
      printf("%c", next[i][j] ? '*' : '.');
    }
    printf("\n");
  }
  return 0;
}
