#include <iostream>
#include <unordered_map>

std::pair<bool, int> majority_element(const int* array, const int size)
{
  std::unordered_map<int, int> element_count;

  int majority_element = 0;
  int majority_element_count = 0;

  for (int i = 0; i < size; ++i)
  {
    const int x = array[i];

    if (element_count.find(x) == element_count.end())
    {
      element_count[x] = 0;
    }

    element_count[x]++;

    const int x_count = element_count[x];

    if (x_count >= majority_element_count)
    {
      majority_element = x;
      majority_element_count = x_count;
    }

    if (majority_element_count > size / 2)
    {
      return {true, majority_element};
    }
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

  auto result = majority_element(array, size);

  if (result.first)
  {
    std::cout << "majority element detected: " << result.second << std::endl;
  }
  else
  {
    std::cout << "no majority element detected" << std::endl;
  }

  return 0;
}
