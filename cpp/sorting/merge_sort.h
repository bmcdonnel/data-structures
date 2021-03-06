#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include <cstdint>

namespace sorting {
  void merge(int32_t* array, int32_t* aux, uint32_t begin, uint32_t middle, uint32_t end);
  void merge_sort(int32_t* array, int32_t* aux, uint32_t begin, uint32_t end);
}

#endif
