#include <ranges>

#include "prime.hpp"

#include "problem10.hpp"

REGISTER_EULER_PROBLEM(euler::problem10, 10, "Multiples of 3 and 5")

constexpr uint64_t UPPER_BOUND = 2000000;

uint64_t euler::problem10::run() {
  uint64_t result{0};

  auto primes =
      numbers::primes() | std::views::take_while([](uint64_t n) noexcept {
        return n < UPPER_BOUND;
      });

  for (auto i : primes) {
    result += i;
  }

  return result;
}
