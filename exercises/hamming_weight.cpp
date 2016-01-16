#include <iostream>
#include <cstdint>

int hamming_weight(uint32_t n)
{
  int weight = 0;

  while(n)
  {
    weight += (n & 1);
    n = n >> 1;
  }

  return weight;
}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <integer>" << std::endl;
    return 1;
  }

  int weight = hamming_weight(std::atoi(argv[1]));

  std::cout << "hamming weight: " << weight << std::endl;

  return 0;
}
