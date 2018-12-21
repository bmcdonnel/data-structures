#ifndef ARRAY_UTILS_H_
#define ARRAY_UTILS_H_

#include <cstdint>
#include <sstream>

namespace utils {
  template <class T>
  std::string array_to_string(T* array, const uint64_t length)
  {
    std::stringstream ss;

    for (uint64_t i = 0; i < length; ++i)
    {
      ss << array[i] << " ";
    }

    return ss.str();
  }

  template <class T>
  void swap(T* x, T* y)
  {
    if(x == y) { return; }

    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
  }

  void reverse_buffer(char* buffer, const uint64_t length);
}

#endif
