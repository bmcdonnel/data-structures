#include <iostream>
#include <stack>

#include "utils/tree_utils.h"

using namespace utils;

int min_depth(TreeNode* node)
{
  if (!node)
  {
    return 0;
  }

  if (!node->left)
  {
    // left is null, so go right
    return 1 + min_depth(node->right);
  }
  else if (!node->right)
  {
    // right is null, so go left
    return 1 + min_depth(node->right);
  }

  // neither is null
  int left_min = min_depth(node->left);
  int right_min = min_depth(node->right);

  // return (the smaller of the two) + 1
  return 1 + ((left_min < right_min) ? left_min : right_min);
}

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " <2n+1 serialized tree values>" << std::endl;
    return 1;
  }

  int size = argc - 2;

  TreeNode* root = create_tree_node(&argv[1], size);

  std::cout << "min depth: " << min_depth(root) << std::endl;
  return 0;
}
