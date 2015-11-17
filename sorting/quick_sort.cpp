#include "quick_sort.h"

void swap(int32_t* x, int32_t* y)
{
  if(x == y) { return; }

  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}

void quick_sort(int32_t* array, uint32_t length)
{
  if (length < 2) { return; }

  // pick the value in the first slot as the pivot
  int32_t pivot_value = array[length / 2];

  uint32_t left = 0;
  uint32_t right = length - 1;

  while (left <= right)
  {
    while (array[left] < pivot_value)
    {
      left++;
    }

    while (array[right] > pivot_value)
    {
      right--;
    }

    if (left >= right)
    {
      break;
    }

    swap(&array[left], &array[right]);
  }

  quick_sort(array, left);
  quick_sort(array + left, length - left);
}
