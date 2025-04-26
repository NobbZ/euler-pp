#include <cstdint>
#include <numeric>
#include <ranges>

#include "fibonacci.hpp"

#include "problem2.hpp"

REGISTER_EULER_PROBLEM(euler::problem2, 2, "Even Fibonacci numbers")

const uint64_t UPPER_BOUND = 4000000;

uint64_t euler::problem2::run() {
  auto even_fibs =
      numbers::fibonacci_sequence |
      std::views::filter([](uint64_t n) noexcept { return n % 2 == 0; }) |
      std::views::take_while(
          [](uint64_t n) noexcept { return n < UPPER_BOUND; }) |
      std::views::common;

  return std::accumulate(even_fibs.begin(), even_fibs.end(), UINT64_C(0));
}
