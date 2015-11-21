#include <iostream>
#include <cstdint>
#include <sstream>

#include "merge_sort.h"
#include "quick_sort.h"

std::string stringify_array(int32_t* array, uint32_t length)
{
  std::stringstream ss;

  for (uint32_t i = 0; i < length; ++i)
  {
    ss << array[i] << " ";
  }

  return ss.str();
}

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " -(merge|quick) <arbitrarily long list of integers>" << std::endl;
    return 1;
  }

  const uint32_t length = argc - 2;

  int32_t array[length];
  int32_t aux[length];

  for (uint32_t i = 0; i < length; ++i)
  {
    array[i] = std::atoi(argv[i + 2]);
  }

  std::memset(aux, 0, length);

  try
  {
    std::cout << "before: " << stringify_array(array, length) << std::endl;

    if (std::strcmp(argv[1], "-merge") == 0)
    {
      sorting::merge_sort(array, aux, 0, length - 1);
    }
    else if (std::strcmp(argv[1], "-quick") == 0)
    {
      sorting::quick_sort(array, length);
    }
    else
    {
      throw std::runtime_error("no sorting type argument was provided");
    }

    std::cout << "after : " << stringify_array(array, length) << std::endl;
  }
  catch(std::runtime_error& e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
