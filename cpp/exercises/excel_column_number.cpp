#include <iostream>

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <Excel column title (A,B,Z,AA,BB...)>" << std::endl;
    return 1;
  }

  char* c = argv[1];
  int column_number = 0;

  while(*c != '\0')
  {
    if (*c < 'A' || *c > 'Z')
    {
      std::cout << "bad character: " << c << std::endl;
    }

    column_number = column_number * 26 + (*c - 'A' + 1);

    c++;
  }

  std::cout << "column number: " << column_number << std::endl;
  return 0;
}
