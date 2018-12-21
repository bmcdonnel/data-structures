# C++ Exercises

## Building

These exercises are built using `cmake` and `ninja` (more info [here](https://ninja-build.org/)). Simply run the build script to kick off compilation.

```bash
bmcdonnel:cpp$ ./build.sh
~/github/data-structures/cpp/build ~/github/data-structures/cpp
-- The C compiler identification is AppleClang 9.0.0.9000039
-- The CXX compiler identification is AppleClang 9.0.0.9000039
-- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc
-- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++
-- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /Users/bmcdonnel/github/data-structures/cpp/build
[89/89] Linking CXX executable sorting/sort_stuff
~/github/data-structures/cpp
bmcdonnel:cpp$
```

## Running

All built executables are placed in the `build` directory.

```bash
bmcdonnel:cpp$ ./build/algorithms/atoi 
usage: ./build/algorithms/atoi <integer>
```
