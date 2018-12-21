#include <iostream>
#include <cstdint>
#include <random>

#include "utils/array_utils.h"

void shuffle(int32_t* array, const uint32_t length)
{
  std::random_device device;
  std::default_random_engine engine(device());

  for (uint32_t i = length - 1; i != 0; --i)
  {
    std::uniform_int_distribution<uint32_t> uniform_distribution(0, i);

    uint32_t j = uniform_distribution(engine);

    utils::swap(&array[i], &array[j]);
  }
}

int main(int argc, char** argv)
{
  const uint32_t length = 52;

  int32_t array[length] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51
  };

  std::cout << "before: " << utils::array_to_string(array, length) << std::endl;
  shuffle(array, length);
  std::cout << "after : " << utils::array_to_string(array, length) << std::endl;
}

