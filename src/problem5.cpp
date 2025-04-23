#include <cstdint>
#include <numeric>
#include <ranges>
#include <string>

#include "problem5.hpp"

REGISTER_EULER_PROBLEM(euler::problem5, 5, "Smallest Multiple")

uint64_t euler::problem5::run() {
  auto divisors{std::ranges::views::iota(1, 20)};

  return std::accumulate(divisors.begin(), divisors.end(), UINT64_C(1), [](uint64_t n, uint64_t acc) __attribute__((const)) {
    return std::lcm(n, acc);
  });
}
