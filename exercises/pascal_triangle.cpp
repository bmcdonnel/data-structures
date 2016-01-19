#include <iostream>
#include <vector>

#include "utils/array_utils.h"

void pascal_triangle(std::vector<std::vector<int>>& result, const int depth, const int total_depth)
{
  if (depth >= total_depth)
  {
    return;
  }

  if (depth == 0)
  {
    result[0] = {1};
  }
  else
  {
    int row_size = result[depth - 1].size() + 1;

    result[depth].resize(row_size);

    result[depth][0] = 1;
    result[depth][row_size - 1] = 1;

    for (int i = 1; i < row_size - 1; ++i)
    {
      result[depth][i] = result[depth - 1][i] + result[depth - 1][i - 1];
    }
  }

  pascal_triangle(result, depth + 1, total_depth);
}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <number of pascal triangle levels>" << std::endl;
    return 1;
  }

  int n = std::atoi(argv[1]);

  std::vector<std::vector<int>> pascal(n);

  pascal_triangle(pascal, 0, n);

  for (auto vec : pascal)
  {
    std::cout << "[ " << utils::array_to_string(static_cast<int*>(vec.data()), vec.size()) << "]" << std::endl;
  }

  return 0;
}
