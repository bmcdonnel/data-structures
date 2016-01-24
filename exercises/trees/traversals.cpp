#include <iostream>
#include <vector>

#include "utils/tree_utils.h"

using namespace utils;

void do_pre_order(TreeNode* node)
{
  std::vector<int> results;

  pre_order_traversal(node, &results);

  std::cout << "pre order: ";

  for (const int value : results)
  {
    std::cout << value << " ";
  }

  std::cout << std::endl;
}

void do_post_order(TreeNode* node)
{
  std::vector<int> results;

  post_order_traversal(node, &results);

  std::cout << "post order: ";

  for (const int value : results)
  {
    std::cout << value << " ";
  }

  std::cout << std::endl;
}

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
  std::vector<std::vector<int>> results;

  level_traversal(node, results);

  std::cout << "level order:" << std::endl;

  for (auto i : results)
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

  TreeNode* root = create_tree_node(&argv[1], size);

  do_pre_order(root);
  do_post_order(root);
  do_in_order(root);
  do_level_order(root);

  return 0;
}
