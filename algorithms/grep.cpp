#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>
#include <cstdint>

#include "utils/array_utils.h"

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    std::cout << "usage: " << argv[0] << " string <filename> " << std::endl;
    return 1;
  }

  struct stat st;
  int rval = stat(argv[2], &st);

  if (rval != 0)
  {
    std::cout << "could not stat file \"" << argv[2] << "\"" << std::endl;
    return 1;
  }

  int32_t filesize = st.st_size;

  std::cout << "mmapping " << argv[2] << " (size " << filesize << ")" << std::endl;
  int fd = open(argv[2], O_RDONLY, 0);

  if (fd == -1)
  {
    std::cout << "could not open file \"" << argv[2] << "\" for reading" << std::endl;
  }

  void* data = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, fd, 0);

  // TODO(bryan) search for the string argument in the mmapped file data
  write(1, data, filesize);

  if (munmap(data, filesize) != 0)
  {
    std::cout << "error unmapping file \"" << argv[2] << "\"" << std::endl;
  }
}
