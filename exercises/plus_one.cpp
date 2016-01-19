#include <iostream>

#include "utils/array_utils.h"

int* plus_one(int* digits, const int size)
{
  int i = size - 1;

  bool carry = false;

  do
  {
    digits[i] = (digits[i] + 1) % 10;

    carry = digits[i] == 0;

    i--;
  } while(carry);

  return digits;
}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <integer>" << std::endl;
    return 1;
  }

  int num_digits = std::strlen(argv[1]);

  int array[num_digits];

  for (int i = 0; i < num_digits; ++i)
  {
    array[i] = argv[1][i] - '0';
  }

  std::cout << "digits provided: " << utils::array_to_string(array, num_digits) << std::endl;
  std::cout << "digits plus one: " << utils::array_to_string(plus_one(array, num_digits), num_digits) << std::endl;

  return 0;
}
