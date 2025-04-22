#include <cstdint>
#include <numeric>
#include <ranges>

#include "numbers.hpp"

#include "problem2.hpp"

const uint64_t UPPER_BOUND = 4000000;

int16_t euler::problem2::id() const { return 2; }

std::string euler::problem2::caption() { return "Even Fibonacci numbers"; }

uint64_t euler::problem2::run() {
  auto even_fibs =
      numbers::fibonacci_sequence |
      std::views::filter([](uint64_t n) noexcept { return n % 2 == 0; }) |
      std::views::take_while([](uint64_t n) noexcept {
        return n < UPPER_BOUND;
      }) | std::views::common;

  return std::accumulate(even_fibs.begin(), even_fibs.end(), UINT64_C(0));
}
