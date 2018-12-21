#include <iostream>
#include <cstdint>
#include <bitset>

uint32_t easy_reverse_bits(const uint32_t number)
{
  uint32_t rebmun = 0;

  for (int i = 0; i < 32; ++i)
  {
    rebmun = (rebmun << 1) + ((number >> i) & 1);
  }

  return rebmun;
}

uint32_t fast_reverse_bits(const uint32_t number)
{
  // 0x01234567 becomes 0x45670123
  uint32_t rebmun = (number >> 16) | (number << 16);

  // flip each neighboring byte
  rebmun = ((rebmun & 0xFF00FF00) >> 8) | ((rebmun & 0x00FF00FF) << 8);

  // flip each neighboring nibble
  rebmun = ((rebmun & 0xF0F0F0F0) >> 4) | ((rebmun & 0x0F0F0F0F) << 4);

  // flip each neighboring half-nibble
  rebmun = ((rebmun & 0xCCCCCCCC) >> 2) | ((rebmun & 0x33333333) << 2);

  // flip each neighboring bit
  rebmun = ((rebmun & 0xAAAAAAAA) >> 1) | ((rebmun & 0x55555555) << 1);

  return rebmun;
}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <integer>" << std::endl;
    return 1;
  }

  uint32_t number = std::atoi(argv[1]);

  uint32_t rebmun = easy_reverse_bits(number);
  uint32_t fast_rebmun = fast_reverse_bits(number);

  std::cout << "number: " << std::bitset<32>(number) << std::endl;
  std::cout << "easy reverse: " << std::bitset<32>(rebmun) << std::endl;
  std::cout << "fast reverse: " << std::bitset<32>(fast_rebmun) << std::endl;

  return 0;
}
