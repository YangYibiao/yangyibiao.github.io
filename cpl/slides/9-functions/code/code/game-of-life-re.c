/* game-of-life-re.c: 生命游戏 (递归/函数化参考演示)
   规则: 活的细胞邻居为 2 或 3 时继续存活; 死的细胞邻居为 3 时复活.
   演示: 每代打印一次棋盘, 共演化 10 代. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 6

const int board[SIZE][SIZE] = {
    {0},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0},
    {0}
};

static void print_board(int b[][SIZE + 2])
{
  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j <= SIZE; j++) {
      printf("%c", b[i][j] ? '*' : ' ');
    }
    printf("\n");
  }
}

void update_board(int b[][SIZE + 2])
{
  int new_board[SIZE + 2][SIZE + 2] = {0};

  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j <= SIZE; j++) {
      int cnt_live = -b[i][j];
      for (int m = i - 1; m <= i + 1; m++) {
        for (int n = j - 1; n <= j + 1; n++) {
          cnt_live += b[m][n];
        }
      }
      if (b[i][j] == 1) {
        new_board[i][j] = (cnt_live == 2 || cnt_live == 3);
      } else {
        new_board[i][j] = (cnt_live == 3);
      }
    }
  }

  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j <= SIZE; j++) {
      b[i][j] = new_board[i][j];
    }
  }
}

int main(void)
{
  int old_board[SIZE + 2][SIZE + 2] = {0};

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      old_board[i + 1][j + 1] = board[i][j];
    }
  }

  for (int i = 0; i < 10; i++) {
    print_board(old_board);
    sleep(1);
    system("clear");
    update_board(old_board);
  }

  return 0;
}
