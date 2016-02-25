#include <iostream>
#include <vector>
#include <stack>

#include "utils/tree_utils.h"

using namespace utils;

TreeNode* tree_from_sorted_array(const int* array, const int size)
{
  if (size == 0)
  {
    return nullptr;
  }
  else if (size == 1)
  {
    return new TreeNode(array[0]);
  }

  int x = size / 2;

  TreeNode* root = new TreeNode(array[x]);

  root->left = tree_from_sorted_array(array, x);
  root->right = tree_from_sorted_array(array + x + 1, size - x - 1);

  return root;
}

int main(const int argc, const char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <sorted array values>" << std::endl;
    return 1;
  }

  int size = argc - 1;
  int array[size];

  for (int i = 0; i < size; ++i)
  {
    array[i] = std::atoi(argv[i + 1]);
  }

  TreeNode* root = tree_from_sorted_array(array, size);

  std::vector<int> in_order;

  in_order_traversal(root, &in_order);

  bool is_equal = true;

  for (int i = 0; i < size; ++i)
  {
    is_equal &= (array[i] == in_order[i]);
  }

  if (is_equal)
  {
    std::cout << "tree creation succeeded!" << std::endl;
  }
  else
  {
    std::cout << "tree creation FAILED!" << std::endl;
  }

  return 0;
}
