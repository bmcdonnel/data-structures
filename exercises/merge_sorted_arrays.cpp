#include <iostream>

#include "utils/array_utils.h"

/**
 * Merge array_b into array_a, assuming array_a has enough space for both sets of elements
 */
void merge_two_arrays(int* array_a, const int size_a, int* array_b, const int size_b)
{
  // end of array_a items
  int a = size_a - 1;

  // end of array_b items
  int b = size_b - 1;

  // end of allocated space in array_a
  int i = size_a + size_b - 1;

  // start merging from the end of the allocated array_a space
  while((a >= 0) && (b >= 0))
  {
    if (array_a[a] > array_b[b])
    {
      array_a[i] = array_a[a];
      a--;
    }
    else
    {
      array_a[i] = array_b[b];
      b--;
    }

    i--;
  }

  // only one of the following loops will actually do anything
  // whichever array ran out first, these will merge any leftovers

  while(a >= 0)
  {
    array_a[i] = array_a[a];
    a--;
    i--;
  }

  while(b >= 0)
  {
    array_a[i] = array_b[b];
    b--;
    i--;
  }
}

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " <list A values> : <list B values" << std::endl;
    return 1;
  }

  int total_size = argc - 2;
  int array_a[total_size];

  int i = 1;

  // stop at the colon
  for (int j = 0; i < argc && argv[i][0] != ':'; ++j, ++i)
  {
    array_a[j] = std::atoi(argv[i]);
  }

  int size_a = i - 1;

  // skip the colon
  i++;

  int size_b = total_size - size_a;
  int array_b[size_b];

  for (int j = 0; i < argc; ++j, ++i)
  {
    array_b[j] = std::atoi(argv[i]);
  }

  std::cout << "array A: " << utils::array_to_string(array_a, size_a) << std::endl;
  std::cout << "array B: " << utils::array_to_string(array_b, size_b) << std::endl;

  merge_two_arrays(array_a, size_a, array_b, size_b);

  std::cout << "merged : " << utils::array_to_string(array_a, total_size) << std::endl;

  return 0;
}

