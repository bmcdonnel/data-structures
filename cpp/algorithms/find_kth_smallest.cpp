#include <iostream>
#include <cstdint>

#include "utils/array_utils.h"

int partition(int k, int32_t* array, int length)
{
  if (length == 1) { return array[0]; }

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

    utils::swap(&array[left], &array[right]);
  }

  if (k < left)
  {
    return partition(k, array, left);
  }
  else
  {
    return partition(k - left, array + left, length - left);
  }
}

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " (k value) <unsorted list of integers>" << std::endl;
    return 1;
  }

  const uint32_t length = argc - 2;

  int32_t array[length];

  for (uint32_t i = 0; i < length; ++i)
  {
    array[i] = std::atoi(argv[i + 2]);
  }

  int k = std::atoi(argv[1]);
  int32_t kth_smallest = partition(k, array, length);

  std::cout << k << " smallest value: " << kth_smallest << std::endl;
}
