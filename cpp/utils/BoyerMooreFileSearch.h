#ifndef BOYER_MOORE_FILE_SEARCH_H_
#define BOYER_MOORE_FILE_SEARCH_H_

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>
#include <cstdint>
#include <exception>

namespace utils {

class BoyerMooreFileSearch
{
public:
  struct Result
  {
    char* match;
    char* line;
    uint64_t match_length;
    uint64_t line_length;
  };

  BoyerMooreFileSearch(const char* pattern, uint32_t patternLength);

  virtual ~BoyerMooreFileSearch();

  void SetFile(const char* filename);
  bool FindNext(Result* result);

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

  /*
   * The bad character table specifies how far away from the end
   * of the pattern the next occurance of a given character is
   *
   * Ex) 0     6       14
   *     SSSSSSZXYZRRRRR
   *     -XYZAAAXYZ-----
   *     ----XYZAAAXYZ--
   *
   *     The first mismatched character in first alignment the 'A'
   *     in column 6. The next 'Z' in the pattern occurs 6 positions
   *     from the end of the pattern
   */
  void PopulateBadCharacterTable();

  void PopulateGoodSuffixTable();

  // 'xyzaaaxyz'  length  9: IsSuffixAlsoPrefix(6) = true
  // 'bxyzaaaxyz' length 10: IsSuffixAlsoPrefix(7) = false
  bool IsSuffixAlsoPrefix(const uint32_t position);

  // 'bbbxyzaaaxyz' length 12: SuffixLength(5) = 3
  // 'aaaxyzaaaxyz' length 12: SuffixLength(5) = 6
  uint32_t SuffixLength(const uint32_t position);

  std::pair<char*, char*> FindNearestLineEndings() const;
};

}

#endif
