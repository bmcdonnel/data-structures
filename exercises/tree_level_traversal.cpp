#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
