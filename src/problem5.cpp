#include <cstdint>
#include <numeric>
#include <ranges>
#include <string>

#include "problem5.hpp"

int16_t euler::problem5::id() { return 5; }

std::string euler::problem5::caption() { return "Smallest Multiple"; }

uint64_t euler::problem5::run() {
  auto divisors{std::ranges::views::iota(1, 20)};

  return std::accumulate(divisors.begin(), divisors.end(), 1, [](uint64_t n, uint64_t acc) {
    return std::lcm(n, acc);
  });
}
