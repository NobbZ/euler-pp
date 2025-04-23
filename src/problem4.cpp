#include "numbers.hpp"

#include "problem4.hpp"

REGISTER_EULER_PROBLEM(euler::problem4, 4, "Largest Palindrome Product");

uint64_t euler::problem4::run() {
  const uint64_t min{100};

  uint64_t num{0};

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
