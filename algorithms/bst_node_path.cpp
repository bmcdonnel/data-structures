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

  return division_count - 1;
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <list of integers>" << std::endl;
    return 1;
  }

  const uint32_t size = argc - 1;

  BinarySearchTree<uint32_t> bst(size);

  for (uint32_t i = 0; i < size; ++i)
  {
    bst.Insert(std::atoi(argv[i + 1]));
  }

  std::cout << bst.ToString() << std::endl;

  std::cout << "tree height: " << bst.TreeHeight() << std::endl;

}
