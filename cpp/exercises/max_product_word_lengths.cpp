#include <iostream>
#include <utility>
#include <unordered_map>

#define max(x,y) x > y ? x : y

int max_product_word_length(const char** words, const int size)
{
  std::unordered_map<int, int> lengths;

  for (int i = 0; i < size; ++i)
  {
    int mask = 0;
    int word_length = std::strlen(words[i]);

    // compute the character mask representation of the word
    const char* c = words[i];
    while (*c != 0x00)
    {
      mask |= (1 << (*c - 'a'));
      c++;
    }

    if (lengths.find(mask) == lengths.end())
    {
      // add it to the map
      lengths[mask] = word_length;
    }
    else
    {
      // update the max length for this mask
      lengths[mask] = max(word_length, lengths[mask]);
    }
  }

  int max_product = 0;

  for (const auto& a : lengths)
  {
    for (const auto& b : lengths)
    {
      if ((a.first & b.first) == 0)
      {
        max_product = max(max_product, a.second * b.second);
      }
    }
  }

  return max_product;
}

int main(const int argc, const char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " <at least two words>" << std::endl;
    return 1;
  }

  int max_product = max_product_word_length(&argv[1], argc - 1);

  std::cout << "max product: " << max_product << std::endl;

  return 0;
}
