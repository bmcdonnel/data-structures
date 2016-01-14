#include <iostream>

bool is_valid_anagram(const std::string& a, const std::string& b)
{
  if (a.size() != b.size())
  {
    return false;
  }

  int count[52] = {0};

  const char* a_str = a.c_str();
  const char* b_str = b.c_str();

  for (int i = 0; i < a.size(); ++i)
  {
    count[a_str[i] - 'a']++;
    count[b_str[i] - 'a']--;
  }

  for (int i = 0; i < 52; ++i)
  {
    if (count[i])
    {
      return false;
    }
  }

  return true;
}

int main(int argc, char** argv)
{
  if (argc != 3)
  {
    std::cout << "usage: " << argv[0] << " <word a> <word b>" << std::endl;
    return 1;
  }

  bool is_valid = is_valid_anagram(argv[1], argv[2]);

  if (is_valid)
  {
    std::cout << argv[1] << " and " << argv[2] << " are valid anagrams." << std::endl;
  }
  else
  {
    std::cout << argv[1] << " and " << argv[2] << " are NOT valid anagrams." << std::endl;
  }

  return 0;
}
