#include <iostream>

#include "utils/array_utils.h"

void mini_sort(const int target, int* array, int& left, int& right)
{
  while (left < right)
  {
    // continue until a target value is found
    while (array[left] != target)
    {
      left++;
    }

    // continue until a non-target value is found
    while (array[right] == target)
    {
      right--;
    }

    if (left >= right)
    {
      break;
    }

    utils::swap(&array[left], &array[right]);
  }
}

/*
 * This is another special case of quick sort:
 *  - the target value is the pivot
 */
void sort_colors(int* array, int length)
{
  if (length < 2) return;

  int left = 0;
  int right = length - 1;

  // one quick sort iteration with a pivot of 2
  mini_sort(2, array, left, right);

  left = 0;

  // another quick sort iteration with a pivot of 1
  mini_sort(1, array, left, right);
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <list of integers in [0, 1, 2]>" << std::endl;
    return 1;
  }

  int size = argc - 1;
  int array[size];

  for (int i = 0; i < size; ++i)
  {
    array[i] = std::atoi(argv[i + 1]);
  }

  std::cout << utils::array_to_string(array, size) << std::endl;

  sort_colors(array, size);

  std::cout << utils::array_to_string(array, size) << std::endl;

  return 0;
}
