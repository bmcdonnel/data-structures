#include <iostream>

#include "utils/BoyerMooreFileSearch.h"

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " pattern filename[ filename ... ] " << std::endl;
    return 1;
  }

  utils::BoyerMooreFileSearch bms(argv[1], std::strlen(argv[1]));

  for(int i = 2; i < argc; ++i)
  {
    try
    {
      bms.SetFile(argv[i]);
    }
    catch(std::runtime_error& e)
    {
      std::cout << e.what() << std::endl;
      continue;
    }

    utils::BoyerMooreFileSearch::Result result;
    bool found = bms.FindNext(&result);

    while (found)
    {
      std::cout << argv[i] << ":" << std::string(result.line, result.line_length) << std::endl;
      found = bms.FindNext(&result);
    }
  }
}
