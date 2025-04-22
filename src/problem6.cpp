#include <cstdint>
#include <string>

#include "problem6.hpp"

uint64_t square_of_sums(uint64_t) __attribute__((const));
uint64_t sum_of_squares(uint64_t) __attribute__((const));

int16_t euler::problem6::id() const { return 6; }

std::string euler::problem6::caption() { return "Sum Square Difference"; }

uint64_t euler::problem6::run() { return square_of_sums(100) - sum_of_squares(100); }

uint64_t square_of_sums(uint64_t n) {
  uint64_t sum{(n * n + n) / 2};

  return sum * sum;
}

uint64_t sum_of_squares(uint64_t n) { return (n * (n + 1) * (2 * n + 1)) / 6; }
