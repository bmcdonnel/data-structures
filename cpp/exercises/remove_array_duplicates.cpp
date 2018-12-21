#include <iostream>

#include "utils/array_utils.h"

int remove_array_duplicates(int* array, const int size)
{
  if (size < 2)
  {
    return size;
  }

  int last_unique = 1;

  for (int i = 1; i < size; ++i)
  {
    if (array[i] != array[i - 1])
    {
      // found a new unique value; move it to the front
      array[last_unique] = array[i];

      last_unique++;
    }
  }

  return last_unique;
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <sorted list of integers>" << std::endl;
    return 1;
  }

  int size = argc - 1;
  int array[size];

  for (int i = 0; i < size; ++i)
  {
    array[i] = std::atoi(argv[i + 1]);
  }

  std::cout << utils::array_to_string(array, size) << std::endl;

  int new_size = remove_array_duplicates(array, size);

  std::cout << utils::array_to_string(array, new_size) << std::endl;

  return 0;
}
