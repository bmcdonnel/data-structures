#include "array_utils.h"

namespace utils
{
  void reverse_buffer(char* buffer, unsigned int length)
  {
    for (int i = 0; i < length / 2; ++i)
    {
      utils::swap(&buffer[i], &buffer[length - 1 - i]);
    }
  }
}

