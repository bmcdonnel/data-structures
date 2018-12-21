#include <iostream>
#include <vector>

#include "utils/tree_utils.h"

using namespace utils;

void find_paths(TreeNode const* node,
                std::string path,
                std::vector<std::string>* paths)
{
  const int value = node->val;

  if (path.size() == 0)
  {
    path += std::to_string(value);
  }
  else
  {
    path += ("->" + std::to_string(value));
  }

  if (!node->left && !node->right)
  {
    paths->push_back(path);
    return;
  }

  if (node->left)
  {
    find_paths(node->left, path, paths);
  }

  if (node->right)
  {
    find_paths(node->right, path, paths);
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

  std::vector<std::string> paths;

  find_paths(root, "", &paths);

  for (const auto& path : paths)
  {
    std::cout << path << std::endl;
  }

  return 0;
}
