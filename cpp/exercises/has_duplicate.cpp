#include <iostream>
#include <unordered_map>

std::pair<bool, int> has_duplicate(const int* array, const int size)
{
  std::unordered_map<int, bool> seen;

  for (int i = 0; i < size; ++i)
  {
    const int x = array[i];

    if (seen.find(x) != seen.end())
    {
      return {true, x};
    }

    seen[x] = true;
  }

  return {false, 0};
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <list of integers" << std::endl;
    return 1;
  }

  const int size = argc - 1;
  int array[size];

  for (int i = 0; i < size; ++i)
  {
    array[i] = std::atoi(argv[i + 1]);
  }

  auto result = has_duplicate(array, size);

  if (result.first)
  {
    std::cout << "duplicate detected: " << result.second << std::endl;
  }
  else
  {
    std::cout << "no duplicates detected" << std::endl;
  }

  return 0;
}
