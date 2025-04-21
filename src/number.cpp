#include "numbers.hpp"

bool euler::numbers::is_palindrome(uint64_t n) {
  uint64_t rev = 0;

  int tmp = n;
  while (tmp != 0) {
    rev = (rev * 10) + (tmp % 10);
    tmp /= 10;
  }

  return rev == n;
}
