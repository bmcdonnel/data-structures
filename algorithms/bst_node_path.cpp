#include <iostream>
#include <cstdint>

#include "utils/binary_search_tree.h"

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <list of integers>" << std::endl;
    return 1;
  }

  const uint32_t size = argc - 1;

  utils::BinarySearchTree bst(size);

  for (uint32_t i = 0; i < size; ++i)
  {
    bst.Insert(std::atoi(argv[i + 1]));
  }

  std::cout << bst.ToString() << std::endl;

  std::cout << "tree height: " << bst.TreeHeight() << std::endl;

}
