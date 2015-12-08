#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>
#include <cstdint>
#include <exception>

#include "utils/array_utils.h"

class BoyerMooreSearch
{
public:
  BoyerMooreSearch(const uint8_t* pattern, uint64_t patternLength) :
    _pattern(pattern),
    _patternLength(patternLength)
  {
    PopulateBadCharacterTable();
  }

  virtual ~BoyerMooreSearch()
  {
    if (munmap(_mmap_data, _filesize) != 0)
    {
      std::cout << "error unmapping file \"" << _filename << "\"" << std::endl;
    }
  }

  void SetFile(const char* filename)
  {
    struct stat st;
    int rval = stat(filename, &st);

    if (rval != 0)
    {
      throw std::runtime_error("could not stat file \"" + _filename + "\"");
    }

    _filesize = st.st_size;

    std::cout << "mmapping " << filename << " (size " << _filesize << ")" << std::endl;
    _fd = open(filename, O_RDONLY, 0);

    if (_fd == -1)
    {
      throw std::runtime_error("could not open file \"" + _filename + "\" for reading");
    }

    _mmap_data = static_cast<uint8_t*>(mmap(NULL, _filesize, PROT_READ, MAP_PRIVATE, _fd, 0));
  }

  char* FindNext()
  {
    return nullptr;
  }

private:
  const uint8_t* _pattern;
  const uint64_t _patternLength;

  std::string _filename;
  int32_t _fd;
  uint64_t _filesize;
  uint8_t* _mmap_data;

  uint8_t _badCharacterTable[256];

  void PopulateBadCharacterTable()
  {
    for (int32_t i = 0; i < 256; ++i)
    {
      _badCharacterTable[i] = _patternLength;
    }

    for (int32_t i = 0; i < _patternLength - 1; ++i)
    {
      _badCharacterTable[_pattern[i]] = _patternLength - 1 - i;
    }
  }
};

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " pattern filename[ filename ... ] " << std::endl;
    return 1;
  }

  BoyerMooreSearch bms(reinterpret_cast<uint8_t*>(argv[1]), std::strlen(argv[1]));

  for(int i = 2; i < argc; ++i)
  {
    try
    {
      bms.SetFile(argv[i]);
    }
    catch(std::runtime_error& e)
    {
      continue;
    }

    char* next = bms.FindNext();
    while (next != nullptr)
    {
      next = bms.FindNext();
    }
  }
}
