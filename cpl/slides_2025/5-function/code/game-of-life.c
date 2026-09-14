#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 6

//const int board1[SIZE][SIZE] = {
//    [0] = {0},
//    [1] = {[1] = 1, [2] = 1},
//    [2] = {[1] = 1, [2] = 1},
//    [3] = {[3] = 1, [4] = 1},
//    [4] = {[3] = 1, [4] = 1}
//};
//
// const int board2[SIZE][SIZE] = {
//     [1][1] = 1, [1][2] = 1,
//     [2][1] = 1, [2][2] = 1,
//     [3][3] = 1, [3][4] = 1,
//     [4][3] = 1, [4][4] = 1
// };
//
//const int board3[SIZE][SIZE] = {
//    0, 0, 0, 0, 0, 0,
//    0, 1, 1, 0, 0, 0,
//    0, 1, 1, 0, 0, 0,
//    0, 0, 0, 1, 1, 0,
//    0, 0, 0, 1, 1, 0
//};

const int board[SIZE][SIZE] = {
    {0},
    {0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0},
    {0}
};

int main() {
  // expand the board
  int old_board[SIZE + 2][SIZE + 2] = {0};
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      old_board[i + 1][j + 1] = board[i][j];
    }
  }

  for (int i = 1; i <= SIZE; i++) {
    for (int j = 1; j <= SIZE; j++) {
      printf("%c", old_board[i][j] ? '*' : ' ');
    }
    printf("\n");
  }

  sleep(1);
  system("clear");

  for (int i = 0; i < 10; i++) {
    int new_board[SIZE + 2][SIZE + 2] = {0};
    // 原来状态，得到新的状态
    for (int i = 1; i <= SIZE; i++) {
      for (int j = 1; j <= SIZE; j++) {
        // 看ij周边邻居中live的细胞的个数
        int cnt_live = -old_board[i][j];
        for (int m = i - 1; m <= i + 1; m++) {
          for (int n = j - 1; n <= j + 1; n++) {
            cnt_live += old_board[m][n];
          }
        }

        if (old_board[i][j] == 1) {
          new_board[i][j] = cnt_live == 2 || cnt_live == 3;
        } else {
          new_board[i][j] = cnt_live == 3;
        }
      }
    }

    for (int i = 1; i <= SIZE; i++) {
      for (int j = 1; j <= SIZE; j++) {
        printf("%c", new_board[i][j] ? '*' : ' ');
      }
      printf("\n");
    }

    sleep(1);
    system("clear");

    // update old_board
    for (int i = 1; i <= SIZE; i++) {
      for (int j = 1; j <= SIZE; j++) {
        old_board[i][j] = new_board[i][j];
      }
    }
  }

  return 0;
}
