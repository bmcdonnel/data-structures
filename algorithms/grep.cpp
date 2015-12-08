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
  struct Result
  {
    char* match;
    uint64_t match_length;
    uint64_t line;
    uint64_t column;
  };

  BoyerMooreSearch(const char* pattern, uint32_t patternLength) :
    _pattern(pattern),
    _patternLength(patternLength),
    _offset(_patternLength - 1),
    _goodSuffixRule(nullptr)
  {
    PopulateBadCharacterTable();
    PopulateGoodSuffixTable();
  }

  virtual ~BoyerMooreSearch()
  {
    if (_mmap_data && munmap(_mmap_data, _filesize) != 0)
    {
      std::cout << "error unmapping file \"" << _filename << "\"" << std::endl;
    }

    if (_goodSuffixRule != nullptr)
    {
      delete[] _goodSuffixRule;
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

    _mmap_data = static_cast<char*>(mmap(NULL, _filesize, PROT_READ, MAP_PRIVATE, _fd, 0));
  }

  bool FindNext(Result* result)
  {
    if (_patternLength == 0)
    {
      *result = { _mmap_data, _filesize, 0, 0 };
      return true;
    }

    while (_offset < _filesize)
    {
      int32_t j = _patternLength - 1;
      while((_mmap_data[_offset] == _pattern[j]) && (j >= 0))
      {
        --_offset;
        --j;
      }

      if (j < 0)
      {
        _offset += (_patternLength + 1);

        // TODO(bryan) compute line numbers.
        //   how does grep do this when so many bytes are skipped during search?
        *result = { _mmap_data + _offset - _patternLength, _patternLength, 0, _offset - _patternLength + 1};
        return true;
      }

      auto a = _badCharacterTable[static_cast<uint8_t>(_mmap_data[_offset])];
      auto b = _goodSuffixRule[j];

      // move forward the max of those two values
      _offset += (a < b ? b : a);
    }

    return false;
  }

private:
  const char* _pattern;
  const uint32_t _patternLength;

  std::string _filename;
  int32_t _fd;
  uint64_t _filesize;
  char* _mmap_data;
  uint64_t _offset;

  char _badCharacterTable[256];
  char* _goodSuffixRule;

  void PopulateBadCharacterTable()
  {
    for (uint32_t i = 0; i < 256; ++i)
    {
      _badCharacterTable[i] = _patternLength;
    }

    for (uint32_t i = 0; i < _patternLength - 1; ++i)
    {
      _badCharacterTable[static_cast<uint8_t>(_pattern[i])] = _patternLength - 1 - i;
    }
  }

  void PopulateGoodSuffixTable()
  {
    if (_goodSuffixRule == nullptr)
    {
      _goodSuffixRule = new char[_patternLength];
    }

    int32_t lastPrefixIndex = _patternLength - 1;

    for (int32_t i = _patternLength - 1; i >= 0; i--)
    {
      if (IsSuffixAlsoPrefix(i + 1))
      {
        lastPrefixIndex = i + 1;
      }

      _goodSuffixRule[i] = lastPrefixIndex + _patternLength - 1 - i;
    }

    for (uint32_t i = 0; i < _patternLength; ++i)
    {
      uint32_t suffixLength = SuffixLength(i);

      if (_pattern[i - suffixLength] != _pattern[_patternLength - 1 - suffixLength])
      {
        _goodSuffixRule[_patternLength - 1 - suffixLength] = _patternLength - 1 - i + suffixLength;
      }
    }
  }

  // IsSuffixAlsoPrefix('bbbxyzaaaxyz', 12, 9) = false
  // IsSuffixAlsoPrefix('xyzaaaxyz', 9, 6) = true
  bool IsSuffixAlsoPrefix(const uint32_t position)
  {
    uint32_t suffixLength = _patternLength - position;

    for (uint32_t i = 0; i < suffixLength; ++i)
    {
      if (_pattern[i] != _pattern[position + i])
      {
        return false;
      }
    }

    return true;
  }

  // 'bbbxyzaaaxyz' length 12: SuffixLength(5) = 3
  // 'aaaxyzaaaxyz' length 12: SuffixLength(5) = 6
  uint32_t SuffixLength(const uint32_t position)
  {
    uint32_t i = 0;

    while((_pattern[position - i] == _pattern[_patternLength - 1 - i]) && (i < position))
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

  BoyerMooreSearch bms(argv[1], std::strlen(argv[1]));

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

    BoyerMooreSearch::Result result;
    bool found = bms.FindNext(&result);

    while (found)
    {
      std::cout << "found " << std::string(result.match, result.match_length)
                << " at column " << result.column << std::endl;
      found = bms.FindNext(&result);
    }
  }
}
