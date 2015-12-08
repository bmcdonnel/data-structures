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
    _patternLength(patternLength),
    _offset(0)
  {
    PopulateBadCharacterTable();
  }

  virtual ~BoyerMooreSearch()
  {
    if (_mmap_data && munmap(_mmap_data, _filesize) != 0)
    {
      std::cout << "error unmapping file \"" << _filename << "\"" << std::endl;
    }
  }

  void SetFile(const char* filename)
  {
    _filename = std::string(filename);

    struct stat st;
    int rval = stat(filename, &st);

    if (rval != 0)
    {
      throw std::runtime_error("could not stat file \"" + _filename + "\"");
    }

    _filesize = st.st_size;

    _fd = open(filename, O_RDONLY, 0);

    if (_fd == -1)
    {
      throw std::runtime_error("could not open file \"" + _filename + "\" for reading");
    }

    _mmap_data = static_cast<uint8_t*>(mmap(NULL, _filesize, PROT_READ, MAP_PRIVATE, _fd, 0));
  }

  uint8_t* FindNext()
  {
    if (_patternLength == 0)
    {
      return _mmap_data;
    }

    // TODO(bryan) include _offset
    int64_t i = _patternLength - 1;
    while (i < _filesize)
    {
      int64_t j = _patternLength - 1;
      while((_mmap_data[i] == _pattern[j]) && (j >= 0))
      {
        --i;
        --j;
      }

      if (j < 0)
      {
        // TODO(bryan) set _offset
        _offset += (i + 1 + _patternLength);
        return _mmap_data + i + 1;
      }
    }

    return nullptr;
  }

private:
  const uint8_t* _pattern;
  const uint64_t _patternLength;

  std::string _filename;
  int32_t _fd;
  uint64_t _filesize;
  uint8_t* _mmap_data;
  uint64_t _offset;

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

  void PopulateGoodSuffixTable()
  {
  }

  // IsSuffixAlsoPrefix('bbbxyzaaaxyz', 12, 9) = false
  // IsSuffixAlsoPrefix('xyzaaaxyz', 9, 6) = true
  bool IsSuffixAlsoPrefix(uint8_t* word, uint64_t wordLength, uint64_t position)
  {
    uint64_t suffixLength = wordLength - position;

    for (uint64_t i = 0; i < suffixLength; ++i)
    {
      if (word[i] != word[position + i])
      {
        return false;
      }
    }

    return true;
  }

  // SuffixLength('bbbxyzaaaxyz', 12, 5) = 3
  // SuffixLength('aaaxyzaaaxyz', 12, 5) = 6
  uint64_t SuffixLength(uint8_t* word, uint64_t wordLength, uint64_t position)
  {
    uint64_t i = 0;

    while((word[position - i] == word[wordLength - 1 - i]) && (i < position))
    {
      ++i;
    }

    return i;
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
      std::cout << e.what() << std::endl;
      continue;
    }

    uint8_t* next = bms.FindNext();
    while (next != nullptr)
    {
      next = bms.FindNext();
    }
  }
}
