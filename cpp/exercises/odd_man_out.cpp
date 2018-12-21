#include <iostream>
#include <unordered_map>

#include "utils/array_utils.h"

int odd_man_out(const int* array, const int size)
{
  int total = 0;
  std::unordered_map<int, bool> seen;

  for (int i = 0; i < size; ++i)
  {
    const int x = array[i];
    if (seen.find(x) == seen.end())
    {
      // not seen before, add to the total
      total += x;
      seen[x] = true;
    }
    else
    {
      // seen before, subtract it and add to map
      total -= x;
    }
  }

  return total;
}

int fast_odd_man_out(const int* array, const int size)
{
  int odd_man_out = 0;

  for (int i = 0; i < size; ++i)
  {
    odd_man_out ^= array[i];
  }

  return odd_man_out;
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <series of duplicate ints with only a single lone value>" << std::endl;
    return 1;
  }

  int size = argc - 1;
  int array[size];

  for (int i = 0; i < size; ++i)
  {
    array[i] = std::atoi(argv[i + 1]);
  }

  std::cout << utils::array_to_string(array, size) << std::endl;

  std::cout << "odd man out: " << odd_man_out(array, size) << std::endl;

  std::cout << "fast odd man out: " << odd_man_out(array, size) << std::endl;

  return 0;
}
