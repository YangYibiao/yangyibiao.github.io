/* inventory.c: 维护零件数据库 (结构体数组版) —— 只写五个函数体
   任务: 支持 i 插入 / s 搜索 / u 更新数量 / p 打印全部 / q 退出
   样例: 依次输入
         i 528 Disk_drive 10
         s 528
         u 528 -2
         p
         q
         期望: 搜索显示 Disk drive, 数量 10; 更新后数量 8; p 打印一行记录
   提示: 用 find_part 按零件号查找, 返回数组下标, 找不到返回 -1;
         插入前先判重、再判数组是否已满 (num_parts == MAX_PARTS). */
#include <stdio.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
};

struct part inventory[MAX_PARTS];
int num_parts = 0;

/* 按零件号查找: 找到返回下标, 找不到返回 -1 */
int find_part(int number)
{
  /* TODO: 遍历 inventory[0..num_parts-1] */
  return -1;
}

/* 插入一个新零件 */
void insert(void)
{
  /* TODO: 判重 (find_part != -1)、判满 (num_parts == MAX_PARTS);
           读入 number、name、on_hand 后 num_parts++ */
}

/* 按零件号搜索并打印 */
void search(void)
{
  /* TODO: 读零件号; find_part; 找到打印 name 和 on_hand, 否则 "Part not found." */
}

/* 按零件号修改库存数量 */
void update(void)
{
  /* TODO: 读零件号与增减量; 找到则 on_hand += change, 否则 "Part not found." */
}

/* 打印全部零件 */
void print(void)
{
  /* TODO: 表头 + 逐行打印 number、name、on_hand */
}

int main(void)
{
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    switch (code) {
      case 'i': insert(); break;
      case 's': search(); break;
      case 'u': update(); break;
      case 'p': print(); break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
