#include <iostream>

// returns true if the only prime factors of number are 2, 3, or 5
bool is_ugly(int number)
{
  if (number == 0)
  {
    return false;
  }

  while(number % 2 == 0)
  {
    number /= 2;
  }

  while(number % 3 == 0)
  {
    number /= 3;
  }

  while(number % 5 == 0)
  {
    number /= 5;
  }

  return number == 1;
}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <integer number>" << std::endl;
    return 1;
  }

  int number = std::atoi(argv[1]);

  if (is_ugly(number))
  {
    std::cout << number << " is ugly" << std::endl;
  }
  else
  {
    std::cout << number << " is NOT ugly" << std::endl;
  }

  return 0;
}
