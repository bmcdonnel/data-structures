#include <iostream>
#include <vector>

#include "utils/tree_utils.h"

using namespace utils;

void do_in_order(TreeNode* node)
{
  std::vector<int> results;

  in_order_traversal(node, &results);

  std::cout << "in order: ";

  for (const int value : results)
  {
    std::cout << value << " ";
  }

  std::cout << std::endl;
}

void do_level_order(TreeNode* node)
{
  std::vector<std::vector<int>> v;

  level_traversal(node, 0, v);

  std::cout << "level order:" << std::endl;

  for (auto i : v)
  {
    std::cout << "[ ";
    for (int j : i)
    {
      std::cout << j << " ";
    }
    std::cout << " ]" << std::endl;
  }
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <2n+1 serialized tree values>" << std::endl;
    return 1;
  }

  int size = argc - 1;

  TreeNode* root = create_tree_node(&argv[1], size, 0);

  do_in_order(root);
  do_level_order(root);

  return 0;
}
