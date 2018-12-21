#include <iostream>
#include <cstdint>

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cout << "usage: " << argv[0] << " (factorial argument)" << std::endl;
    return 1;
  }

  int32_t factorial_arg = std::atoi(argv[1]);

  int32_t num_zeroes = 0;

  for (int32_t divisor = 5; factorial_arg/divisor >= 1; divisor *= 5)
  {
    num_zeroes += factorial_arg/divisor;
  }

  std::cout << factorial_arg << "! has " << num_zeroes << " trailing zeroes" << std::endl;
}
