#include "array_utils.h"

namespace utils
{
  void reverse_buffer(char* buffer, const uint64_t length)
  {
    for (uint64_t i = 0; i < length / 2; ++i)
    {
      utils::swap(&buffer[i], &buffer[length - 1 - i]);
    }
  }
}

