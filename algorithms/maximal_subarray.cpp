#include <iostream>
#include <cstdint>

#include "utils/array_utils.h"

void maximal_subarray(
  const int32_t* array,
  const uint32_t length,
  int32_t* max_start,
  uint32_t* max_length)
{
  int32_t maxEndingHere = 0;
  int32_t maxSoFar = 0;

  for (uint32_t i = 0; i < length; ++i)
  {
    if (maxEndingHere + array[i] > 0)
    {
      maxEndingHere =  maxEndingHere + array[i];
    }
    else
    {
      maxEndingHere = 0;
    }

    maxSoFar = (maxEndingHere > maxSoFar) ? maxEndingHere : maxSoFar;
  }

  max_start = nullptr;
  *max_length = 0;
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " <list of integers>" << std::endl;
    return 1;
  }

  const uint32_t length = argc - 1;

  int32_t array[length];

  for (uint32_t i = 0; i < length; ++i)
  {
    array[i] = std::atoi(argv[i + 1]);
  }

  int32_t* subarray = nullptr;
  uint32_t subarray_length = 0;

  maximal_subarray(array, length, subarray, &subarray_length);

  std::cout << "maximal subarray: " << utils::array_to_string(subarray, subarray_length) << std::endl;
}
