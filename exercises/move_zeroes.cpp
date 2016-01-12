#include <iostream>

#include "utils/array_utils.h"

void move_zeroes(int* array, int length)
{
  if (length < 2) return;

  int left = 0;
  int right = length - 1;

  while (left < right)
  {
    // continue until a 0 is found
    while (array[left] != 0)
    {
      left++;
    }

    // continue until a non-zero is found
    while (array[right] == 0)
    {
      right--;
    }

    if (left >= right)
    {
      break;
    }

    std::cout << "swapping " << left << " and " << right << std::endl;
    utils::swap(&array[left], &array[right]);
    std::cout << utils::array_to_string(array, length) << std::endl;
  }
}

int main(int arc, char** argv)
{
  int array[8] = { 0, 1, 12, 8 , 0, 25, 0, 7 };

  std::cout << utils::array_to_string(array, 8) << std::endl;
  move_zeroes(array, 8);
}
