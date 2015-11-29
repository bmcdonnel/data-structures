#include <iostream>
#include <cstdint>

#include "utils/binary_search_tree.h"

uint32_t log_base_2(const uint32_t value)
{
  uint32_t temp = value;
  uint32_t division_count = 0;

  while (temp > 0)
  {
    temp = temp >> 1;
    division_count++;
  }

  return division_count;
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <list of integers>" << std::endl;
    return 1;
  }

  const uint32_t input_length = argc - 1;
  const uint32_t tree_height = log_base_2(input_length);

  std::cout << "tree height: " << tree_height << std::endl;
}
