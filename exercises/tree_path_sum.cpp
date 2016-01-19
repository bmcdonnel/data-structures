#include <iostream>
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create_tree_node(char** array, int size, int i)
{
  if (i >= size)
  {
    return nullptr;
  }

  if (array[i] && array[i][0] == 'x')
  {
    return nullptr;
  }

  int value = std::atoi(array[i]);

  TreeNode* node = new TreeNode(value);

  node->left = create_tree_node(array, size, (2 * i) + 1);
  node->right = create_tree_node(array, size, (2 * i) + 2);

  return node;
}

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
