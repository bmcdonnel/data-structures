#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <cstdint>

namespace sorting {
  void swap(int32_t* x, int32_t* y);
  void quick_sort(int32_t* array, uint32_t length);
}

#endif
