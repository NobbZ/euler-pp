#include <numeric>
#include <ranges>

#include "problem1.hpp"

static bool problem1_registered = euler::euler::register_problem<euler::problem1>();

int16_t euler::problem1::id() const { return 1; }

std::string euler::problem1::caption() { return "Multiples of 3 and 5"; }

uint64_t euler::problem1::run() {
  auto multiples = std::ranges::views::iota(1, 1000) |
                   std::ranges::views::filter([](uint64_t i) noexcept {
                     return i % 3 == 0 || i % 5 == 0;
                   });

  return std::accumulate(multiples.begin(), multiples.end(), 0ULL);
}
