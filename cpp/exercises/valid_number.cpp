#include <iostream>

bool is_valid_number(const char* number_string)
{
  bool valid = true;

  int num_decimals = 0;

  int exponent_index = -1;
  bool has_exponent = false;

  int i = 0;
  const char* c = number_string;
  while (*c != 0x00 && valid)
  {
    if (*c >= '0' && *c <= '9')
    {
      // still valid
    }
    else if (*c == '-')
    {
      if (number_string[i + 1] == 0x00)
      {
        // must be followed by something
        return false;
      }
      else if (i != 0 && !(has_exponent && exponent_index == i - 1))
      {
        // must either be the first character, or right after 'e'
        return false;
      }
    }
    else if (*c == '.')
    {
      if (number_string[i + 1] == 0x00)
      {
        // must be followed by something
        return false;
      }
      else if (num_decimals == 0)
      {
        num_decimals++;
      }
      else if (num_decimals == 1 && has_exponent)
      {
        // allowed two decimals, but only if there's an exponent
        num_decimals++;
      }
      else
      {
        return false;
      }
    }
    else if (*c == 'e')
    {
      if (number_string[i + 1] == 0x00)
      {
        // must be followed by something
        return false;
      }
      else if (!has_exponent)
      {
        has_exponent = true;
        exponent_index = i;
      }
      else if (has_exponent)
      {
        return false;
      }
    }
    else
    {
      // any other characters are invalid
      return false;
    }

    c++;
    i++;
  }

  return valid;
}

int main(const int argc, const char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <int/float/scientific number in any format>" << std::endl;
    return 1;
  }

  if (is_valid_number(argv[1]))
  {
    std::cout << argv[1] << " is a valid number" << std::endl;
  }
  else
  {
    std::cout << argv[1] << " is NOT a valid number" << std::endl;
  }

  return 0;
}
