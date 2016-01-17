#include <iostream>

bool is_power_of_two(int x)
{
  if (x <= 0) return false;

  return (x & (x - 1)) == 0;
}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <integer>" << std::endl;
    return 1;
  }

  int number = std::atoi(argv[1]);

  if (is_power_of_two(number))
  {
    std::cout << number << " is a power of two" << std::endl;
  }
  else
  {
    std::cout << number << " is NOT a power of two" << std::endl;
  }

  return 0;
}
