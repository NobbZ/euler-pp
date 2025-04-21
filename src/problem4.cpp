#include <vector>

#include "numbers.hpp"
#include "problem4.hpp"

int16_t euler::problem4::id() { return 4; }

std::string euler::problem4::caption() { return "Largest Palindrome Product"; }

std::string euler::problem4::description() {
  return "A palindromic number reads the same both ways. "
         "The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.\n"
         "\n"
         "Find the largest palindrome made from the product of two 3-digit numbers.\n";
}

uint64_t euler::problem4::run() {
  const uint64_t min { 100 };

  uint64_t num { 0 };

  for (uint64_t i = 999; i >= min; i--) {
    for (uint64_t j = 999; j >= i; j--) {
      uint64_t n = j * i;

      if (numbers::is_palindrome(n) && n > num) {
        num = n;
      }
    }
  }

  return num;
}
