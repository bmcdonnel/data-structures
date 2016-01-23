#include <iostream>
#include <vector>
#include <queue>

#include "utils/tree_utils.h"

using namespace utils;

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <2n+1 serialized tree values>" << std::endl;
    return 1;
  }

  int size = argc - 1;

  TreeNode* root = create_tree_node(&argv[1], size, 0);

  std::vector<std::vector<int>> v;

  level_traversal(root, 0, v);

  for (auto i : v)
  {
    std::cout << "[ ";
    for (int j : i)
    {
      std::cout << j << " ";
    }
    std::cout << " ]" << std::endl;
  }

  return 0;
}
