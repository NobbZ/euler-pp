#include <cstdint>
#include <ranges>
#include <string>

#include "problem9.hpp"

REGISTER_EULER_PROBLEM(euler::problem9, 9, "Special Pythagorean Triplet")

constexpr uint64_t target_sum = 1000;

uint64_t euler::problem9::run() {
  for (uint64_t a : std::ranges::views::iota(UINT64_C(1), target_sum)) {
    for (uint64_t b : std::ranges::views::iota(a + 1, target_sum)) {
      uint64_t c = target_sum - a - b;
 
      if (c > b && a * a + b * b == c * c) {
        return a * b * c;
      }
    }
  }
  
  throw std::runtime_error("unreachable");
}
