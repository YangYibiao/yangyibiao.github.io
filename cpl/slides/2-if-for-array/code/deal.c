/* 随机发牌 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
  int in_hand[NUM_SUITS][NUM_RANKS] = {0};   /* 52 张牌, 0=还没发 */
  int num_cards, rank, suit;
  const char rank_code[] = {'2','3','4','5','6','7','8',
                            '9','t','j','q','k','a'};   /* t 代表 10 */
  const char suit_code[] = {'c','d','h','s'};

  srand((unsigned) time(NULL));
  printf("输入手牌数量: ");
  scanf("%d", &num_cards);
  printf("你的牌:");
  while (num_cards > 0) {
    suit = rand() % NUM_SUITS;    /* 随机花色 0~3 */
    rank = rand() % NUM_RANKS;    /* 随机等级 0~12 */
    if (!in_hand[suit][rank]) {
      in_hand[suit][rank] = 1;
      num_cards--;
      printf(" %c%c", rank_code[rank], suit_code[suit]);
    }
  }
  printf("\n");
  return 0;
}
