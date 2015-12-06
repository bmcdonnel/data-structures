#include <iostream>
#include <cstdint>

#include "utils/array_utils.h"

std::pair<uint32_t, uint32_t> findBestDealIndices(int32_t const* array, const uint32_t length, bool isShortSale=false)
{
  // a is always less than b
  uint32_t index_a = 0;
  uint32_t index_b = 0;

  int32_t bestDeal = 0;

  // TODO(bryan) is there a way to do this that isn't O(n^2)
  for (uint32_t i = 0; i < length; ++i)
  {
    for (uint32_t j = i; j < length; ++j)
    {
      if (isShortSale && array[i] - array[j] >= bestDeal)
      {
        index_a = i;
        index_b = j;
        bestDeal = array[index_a] - array[index_b];
      }
      else if (!isShortSale && array[j] - array[i] >= bestDeal)
      {
        index_a = i;
        index_b = j;
        bestDeal = array[index_b] - array[index_a];
      }
    }
  }

  return std::pair<uint32_t, uint32_t>(index_a, index_b);
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

  utils::array_to_string(array, length);

  const std::pair<uint32_t, uint32_t> longSale = findBestDealIndices(array, length, false);

  std::cout << "buy at " << array[longSale.first] << " on day " << longSale.first << "; " <<
               "sell at " << array[longSale.second] << " on day " << longSale.second  << std::endl;


  const std::pair<uint32_t, uint32_t> shortSale = findBestDealIndices(array, length, true);
  std::cout << "sell short at " << array[shortSale.first] << " on day " << shortSale.first << "; " <<
               "buy at " << array[shortSale.second] << " on day " << shortSale.second  << std::endl;
}
