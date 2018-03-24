#include "quick_sort.h"
#include "utils/array_utils.h"

#include <iostream>

namespace sorting
{
  void quick_sort(int32_t* array, const uint32_t low, const uint32_t high)
  {
    if (low >= high) { return; }

    const uint32_t p = partition(array, low, high);

    quick_sort(array, low, p);
    quick_sort(array, p + 1, high);
  }

  uint32_t partition(int32_t* array, const uint32_t low, const uint32_t high)
  {
    const uint32_t pivot = array[low];
    uint32_t i = low - 1;
    uint32_t j = high + 1;

    while (true)
    {
      do
      {
        i++;
      } while (array[i] < pivot);

      do
      {
        j--;
      } while (array[j] > pivot);

      if (i >= j)
      {
        return j;
      }

      utils::swap(&array[i], &array[j]);
    }
  }
}
