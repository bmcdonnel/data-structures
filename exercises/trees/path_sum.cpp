#include <iostream>
#include <stack>

#include "utils/tree_utils.h"

using namespace utils;

bool has_path_sum(TreeNode* node, const int parent_sum, const int target_sum)
{
  if (!node)
  {
    return parent_sum == target_sum;
  }

  if (has_path_sum(node->left, parent_sum + node->val, target_sum))
  {
    return true;
  }

  if (has_path_sum(node->right, parent_sum + node->val, target_sum))
  {
    return true;
  }

  return false;
}

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " <desired root-to-leaf sum> <2n+1 serialized tree values>" << std::endl;
    return 1;
  }

  int target_sum = std::atoi(argv[1]);

  int size = argc - 2;

  TreeNode* root = create_tree_node(&argv[2], size, 0);

  if (has_path_sum(root, 0, target_sum))
  {
    std::cout << "sum found" << std::endl;
  }
  else
  {
    std::cout << "sum NOT found" << std::endl;
  }

  return 0;
}
