#include <iostream>
#include <cstdint>
#include <cstring>
#include <stdexcept>

void swap(char* x, char* y)
{
  if(x == y) { return; }

  *x = *x ^ *y;
  *y = *x ^ *y;
  *x = *x ^ *y;
}

void reverse_buffer(char* buffer, unsigned int length)
{
  for (int i = 0; i < length / 2; ++i)
  {
    swap(&buffer[i], &buffer[length - 1 - i]);
  }
}

void reverse_words(char* buffer, unsigned int length)
{
  if (length == 0)
  {
    throw std::runtime_error("invalid length " + std::to_string(length));
  }

  reverse_buffer(buffer, length);

  std::cout << "during: '" << buffer << "'" << std::endl;

  char* begin = buffer;
  char* end = buffer;

  while(end < buffer + length)
  {
    if (*end != ' ')
    {
      end += 1;
      continue;
    }

    reverse_buffer(begin, end - begin);

    begin = end + 1;
    end = begin;
  }

  reverse_buffer(begin, end - begin);
}

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " <two or more words>" << std::endl;
    return -1;
  }

  int total_length = 0;

  for (int i = 1; i < argc; ++i)
  {
    total_length += std::strlen(argv[i]);
  }

  // add the number of spaces
  total_length += argc - 2;

  std::cout << "total length: " << total_length << std::endl;

  // add one for the null
  char all_args[total_length + 1];
  char* pointer = all_args;

  for (int i = 1; i < argc; ++i)
  {
    std::strcpy(pointer, argv[i]);
    pointer += std::strlen(argv[i]);

    if (i != argc - 1)
    {
      *pointer = ' ';
      pointer += 1;
    }
  }

  *pointer = 0;

  try
  {
    std::cout << "before: '" << all_args << "'" << std::endl;

    reverse_words(all_args, total_length);

    std::cout << "after : '" << all_args << "'" << std::endl;
  }
  catch( std::runtime_error & e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

