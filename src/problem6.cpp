#include <cstdint>
#include <string>

#include "problem6.hpp"

REGISTER_EULER_PROBLEM(euler::problem6, 6, "Sum Square Difference")

constexpr uint64_t square_of_sums(uint64_t) __attribute__((const));
constexpr uint64_t sum_of_squares(uint64_t) __attribute__((const));

uint64_t euler::problem6::run() {
  return square_of_sums(100) - sum_of_squares(100);
}

constexpr uint64_t square_of_sums(uint64_t n) {
  uint64_t sum{(n * n + n) / 2};

  return sum * sum;
}

constexpr uint64_t sum_of_squares(uint64_t n) {
  return (n * (n + 1) * (2 * n + 1)) / 6;
}
