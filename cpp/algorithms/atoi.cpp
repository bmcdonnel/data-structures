#include <iostream>
#include <cstdint>
#include <cstring>
#include <stdexcept>

int my_atoi( char* buffer, unsigned int length )
{
  if (length == 0)
  {
    throw std::runtime_error("invalid length " + std::to_string(length));
  }

  int result = 0;
  unsigned int i = 0;

  bool is_negative = buffer[0] == '-';

  if (is_negative)
  {
    if (length == 1)
    {
      throw std::runtime_error("invalid string " + std::string(buffer));
    }

    i++;
  }

  while(i < length)
  {
    result *= 10;

    if (buffer[i] < '0' || buffer[i] > '9')
    {
      throw std::runtime_error("invalid character in column " + std::to_string(i));
    }

    result += buffer[i] - '0';

    if (result < 0)
    {
      throw std::runtime_error("overflow detected");
    }

    i++;
  }

  return is_negative ? -1 * result : result;
}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <integer>" << std::endl;
    return -1;
  }

  try
  {
    std::cout << my_atoi(argv[1], std::strlen(argv[1])) << std::endl;
  }
  catch( std::runtime_error & e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
