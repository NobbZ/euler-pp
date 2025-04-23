#include <numeric>
#include <ranges>

#include "problem1.hpp"

REGISTER_EULER_PROBLEM(euler::problem1, 1, "Multiples of 3 and 5");

uint64_t euler::problem1::run() {
  auto multiples = std::ranges::views::iota(1, 1000) |
                   std::ranges::views::filter([](uint64_t i) noexcept {
                     return i % 3 == 0 || i % 5 == 0;
                   });

  return std::accumulate(multiples.begin(), multiples.end(), 0ULL);
}
