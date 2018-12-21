#include "BoyerMooreFileSearch.h"

namespace utils {

BoyerMooreFileSearch::BoyerMooreFileSearch(const char* pattern, uint32_t patternLength) :
  _pattern(pattern),
  _patternLength(patternLength),
  _offset(_patternLength - 1),
  _goodSuffixRule(nullptr)
{
  PopulateBadCharacterTable();
  PopulateGoodSuffixTable();
}

BoyerMooreFileSearch::~BoyerMooreFileSearch()
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

void BoyerMooreFileSearch::SetFile(const char* filename)
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

bool BoyerMooreFileSearch::FindNext(Result* result)
{
  if (_patternLength == 0)
  {
    *result = { _mmap_data, _mmap_data, _filesize, _filesize };
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
      // move pointer forward to the beginning of the match
      _offset++;

      auto lineEndingsPair = FindNearestLineEndings();

      *result = { _mmap_data + _offset,
                  lineEndingsPair.first,
                  _patternLength,
                  static_cast<uint64_t>(lineEndingsPair.second - lineEndingsPair.first) + 1
                };

      // move pointer forward to prepare for next match
      _offset += _patternLength;

      return true;
    }

    auto a = _badCharacterTable[static_cast<uint8_t>(_mmap_data[_offset])];
    auto b = _goodSuffixRule[j];

    // move forward the max of those two values
    _offset += (a < b ? b : a);
  }

  return false;
}

void BoyerMooreFileSearch::PopulateBadCharacterTable()
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

void BoyerMooreFileSearch::PopulateGoodSuffixTable()
{
  if (_goodSuffixRule == nullptr)
  {
    _goodSuffixRule = new char[_patternLength];
  }

  int32_t lastPrefixIndex = _patternLength - 1;

  /*
   * Ex) pattern: 'zyxxyz' length 6 -> _goodSuffixRule = { 10, 9, 8, 7, 6, 6 }
   * Ex) pattern: 'xyzxyz' length 6 -> _goodSuffixRule = { 8, 7, 6, 8, 7, 6 }
   * Ex) pattern: 'axyzbxyz' length 8 -> _goodSuffixRule = { 15, 14, 13, 12, 11, 10, 9, 8 }
   */
  for (int32_t i = _patternLength - 1; i >= 0; i--)
  {
    if (IsSuffixAlsoPrefix(i + 1))
    {
      lastPrefixIndex = i + 1;
    }

    _goodSuffixRule[i] = lastPrefixIndex + _patternLength - 1 - i;
  }

  /*
   * Ex) pattern: 'zyxxyz' length 6 -> _goodSuffixRule = { 10, 9, 8, 7, 6, 1 }
   * Ex) pattern: 'xyzxyz' length 6 -> _goodSuffixRule = { 8, 7, 6, 8, 7, 1 }
   * Ex) pattern: 'axyzbxyz' length 8 -> _goodSuffixRule = { 15, 14, 13, 12, 7, 10, 9, 1 }
   */
  for (uint32_t i = 0; i < _patternLength; ++i)
  {
    uint32_t suffixLength = SuffixLength(i);

    if (_pattern[i - suffixLength] != _pattern[_patternLength - 1 - suffixLength])
    {
      _goodSuffixRule[_patternLength - 1 - suffixLength] = _patternLength - 1 - i + suffixLength;
    }
  }
}

bool BoyerMooreFileSearch::IsSuffixAlsoPrefix(const uint32_t position)
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

uint32_t BoyerMooreFileSearch::SuffixLength(const uint32_t position)
{
  uint32_t i = 0;

  while((_pattern[position - i] == _pattern[_patternLength - 1 - i]) && (i < position))
  {
    ++i;
  }

  return i;
}

std::pair<char*, char*> BoyerMooreFileSearch::FindNearestLineEndings() const
{
  std::pair<char*, char*> lineEndings;

  char* c = _mmap_data + _offset;
  while (*c != '\n' && c > _mmap_data)
  {
    --c;
  }

  if (*c == '\n') c++;

  lineEndings.first = c;

  c = _mmap_data + _offset;
  while (*c != '\n' && c < _mmap_data + _filesize)
  {
    c++;
  }

  if (*c == '\n') c--;

  lineEndings.second = c;

  return lineEndings;
}

}
