#include <iostream>

int roman_to_int(const char c)
{
  switch(c)
  {
    case 'M':
    case 'm':
        return 1000;
    case 'D':
    case 'd':
        return 500;
    case 'C':
    case 'c':
        return 100;
    case 'L':
    case 'l':
        return 50;
    case 'X':
    case 'x':
        return 10;
    case 'V':
    case 'v':
        return 5;
    case 'I':
    case 'i':
        return 1;
    default:
        return 0;
  }
}

int convert(char* roman_numeral, int size)
{
  int result = 0;
  int i = size - 1;
  int previous_value = 0;

  while (i >= 0)
  {
    int current_value = roman_to_int(roman_numeral[i]);

    if (current_value >= previous_value)
    {
      result += current_value;
    }
    else
    {
      result -= current_value;
    }

    previous_value = current_value;

    --i;
  }

  return result;
}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <roman numeral>" << std::endl;
    return 1;
  }

  int integer_value = convert(argv[1], std::strlen(argv[1]));

  std::cout << "integer value: " << integer_value << std::endl;

  return 0;
}
