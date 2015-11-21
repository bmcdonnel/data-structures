#include "array_utils.h"

namespace utils
{
  void swap(int32_t* x, int32_t* y)
  {
    if(x == y) { return; }

    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
  }
}

