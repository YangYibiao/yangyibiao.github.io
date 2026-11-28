#include <stdio.h>

void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int start, int end);

void printArr(int arr[], int len)
{
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  int arr[] = {38, 27, 43, 3, 9, 82, 10};

  int len = sizeof(arr) / sizeof(arr[0]);
  printf("Before sorting\n");
  printArr(arr, len);

  mergeSort(arr, 0, len - 1);

  printf("After sorting\n");
  printArr(arr, len);

  return 0;
}

// 对数组arr从start到end位置进行归并排序
void mergeSort(int arr[], int start, int end)
{
  // 如果当前的数组有至少一个元素
  if (start < end)
  {
    // 取中间位置
    int mid = (start + end) / 2;

    // 对左半边进行排序
    mergeSort(arr, start, mid);

    // 对右半边进行排序
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
  }
}

// 合并arr两个子数组: 子数组1 arr[start,mid], 子数组2 arr[mid+1, end]
void merge(int arr[], int start, int mid, int end)
{
  int len = end - start + 1;
  int narr[len];
  int itera = start, iterb = mid + 1;
  int index = 0;
  // 当前没有访问到两个子数组的边界
  while (itera <= mid && iterb <= end) {
    // 当前两个数组当前访问的最小值加到新数组narr中
    if (arr[itera] <= arr[iterb]) {
      narr[index++] = arr[itera++];
    } else {
      narr[index++] = arr[iterb++];
    }
  }

  // 如果还有，将子数组1的部分添加到新数组narr中
  while (itera <= mid)
    narr[index++] = arr[itera++];
  // 如果还有，将子数组2的部分添加到新数组narr中
  while (iterb <= end)
    narr[index++] = arr[iterb++];

  for (int i = 0; i < len; i++) {
    // 更新数组arr[start, end]的所有值
    arr[start + i] = narr[i];
  }
}
