/* invclear.c: 把零件记录文件里每个零件的 on_hand 清零
   文件 inventory.dat 按顺序存放 struct part 记录 (二进制).
   任务:
     1. 用 "rb+" 打开 inventory.dat
     2. 用 fread 把记录读入数组, 得到记录数
     3. 把每条记录的 on_hand 置 0
     4. 用 rewind 回到文件开头, 再用 fwrite 写回
   提示: fread 返回实际读到的记录数; rewind(fp) 等价于 fseek(fp, 0L, SEEK_SET). */
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

int main(void)
{
  struct part inventory[MAX_PARTS];
  int num_parts;
  FILE *fp;

  /* TODO: 以 "rb+" 打开 inventory.dat, 判 NULL */
  /* TODO: fread 读入记录, 结果存入 num_parts */
  /* TODO: 循环把 inventory[i].on_hand 置 0 */
  /* TODO: rewind, fwrite 写回, fclose */
  return 0;
}
