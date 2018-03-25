#include <iostream>

bool is_valid_anagram(const std::string& a, const std::string& b)
{
  if (a.size() != b.size())
  {
    return false;
  }

  // size of 256 for all possible asci characters
  int character_count[256] = {0};

  const char* a_str = a.c_str();
  const char* b_str = b.c_str();

  // at this point, both strings are know to be the same size
  for (int i = 0; i < a.size(); ++i)
  {
    // increment the count for each of A's characters
    character_count[a_str[i] - 'a']++;
    // decrement the count for each of A's characters
    character_count[b_str[i] - 'a']--;
  }

  for (int i = 0; i < 256; ++i)
  {
    if (character_count[i])
    {
      // if any character has a non-zero count, the
      // two strings are not anagrams of each other
      return false;
    }
  }

  // success
  return true;
}

int main(int argc, char** argv)
{
  if (argc != 3)
  {
    std::cout << "usage: " << argv[0] << " <alpha-numeric word A> <alpha-numeric word B>" << std::endl;
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
