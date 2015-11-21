#ifndef ARRAY_UTILS_H_
#define ARRAY_UTILS_H_

#include <cstdint>

namespace utils {
  template <class T>
  void swap(T* x, T* y)
  {
    if(x == y) { return; }

    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
  }

  void reverse_buffer(char* buffer, unsigned int length);
}

#endif
