#include <iostream>
#include <vector>

#include "utils/tree_utils.h"

using namespace utils;

void level_traversal(const TreeNode* node, const int depth, std::vector<std::vector<int>>& result)
{
  if (!node)
  {
    return;
  }

  if (depth >= result.size())
  {
    result.push_back(std::vector<int>());
  }

  result[depth].push_back(node->val);
  level_traversal(node->left, depth + 1, result);
  level_traversal(node->right, depth + 1, result);
}

void inorder_traversal(TreeNode* node, std::vector<int>* traversal)
{
  if (!node)
  {
    return;
  }

  inorder_traversal(node->left, traversal);

  traversal->push_back(node->val);

  inorder_traversal(node->right, traversal);
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

  std::vector<int> results;

  inorder_traversal(root, &results);

  for (const int value : results)
  {
    std::cout << value << " ";
  }

  std::cout << std::endl;

  return 0;
}
