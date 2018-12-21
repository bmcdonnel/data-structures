#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <cstdint>

namespace sorting {
  void quick_sort(int32_t* array, const uint32_t low, const uint32_t high);
  uint32_t partition(int32_t* array, const uint32_t low, const uint32_t high);
}

#endif
