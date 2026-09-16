/* 使用快速排序算法对整数数组进行排序 (无指针版) */
/*
 * 改编自 K.N. King《C Programming: A Modern Approach》第 9 章 qsort.c
 * 全部使用数组下标, 第 8 周学完数组与函数即可读懂
 */

#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void)
{
  int a[N], i;

  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  quicksort(a, 0, N - 1);

  printf("In sorted order: ");
  for (i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");

  return 0;
}

/* 递归: 划分后分别排序左右两半 */
void quicksort(int a[], int low, int high)
{
  int middle;

  if (low >= high) return;          /* 基准情形: 0 或 1 个元素已有序 */
  middle = split(a, low, high);     /* 划分: 小的在左, 大的在右 */
  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

/* 划分: 以 a[low] 为基准, 返回基准最终所在的下标 */
int split(int a[], int low, int high)
{
  int part_element = a[low];

  for (;;) {
    while (low < high && part_element <= a[high])
      high--;
    if (low >= high) break;
    a[low++] = a[high];

    while (low < high && a[low] <= part_element)
      low++;
    if (low >= high) break;
    a[high--] = a[low];
  }

  a[high] = part_element;
  return high;
}
