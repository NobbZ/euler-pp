#include <algorithm>
#include <cstdint>
#include <ranges>
#include <string>

#include "problem5.hpp"

int16_t euler::problem5::id() { return 5; }

std::string euler::problem5::caption() { return "Smallest Multiple"; }

std::string euler::problem5::description() { return ""; }

uint64_t euler::problem5::run() {
  uint64_t num{2};

  while (!std::ranges::all_of(std::ranges::views::iota(1, 20),
                             [num](uint64_t n) { return num % n == 0; })) {
    num += 2;
  }

  return num;
}
