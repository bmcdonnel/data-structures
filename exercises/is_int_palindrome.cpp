#include <iostream>

bool is_palindrome(int number)
{
  if (number < 0)
  {
    // negatives can't be palindromes
    return false;
  }
  else if (number != 0 && (number % 10 == 0))
  {
    // if it ends in zero and the number isn't zero,
    // it can't be a palindrome
    return false;
  }

  // collect half of the digits in reverse order
  int flipped_half = 0;

  // continue until we've consumed half of number's digits
  while(number > flipped_half)
  {
    // peel off another digit
    flipped_half = (flipped_half * 10) + number % 10;
    number /= 10;
  }

  // if the number of digits was even, the two halves will match up directly
  // if the number of digits was odd, discard the "middle" digit and check for a match
  return (flipped_half == number || flipped_half/10 == number);
}

int main(int argc, char** argv)
{
  if (argc != 2)
  {
    std::cout << "usage: " << argv[0] << " <integer>" << std::endl;
    return 1;
  }

  int number = std::atoi(argv[1]);

  if (is_palindrome(number))
  {
    std::cout << number << " is a palindrome" << std::endl;
  }
  else
  {
    std::cout << number << " is NOT a palindrome" << std::endl;
  }

  return 0;
}
