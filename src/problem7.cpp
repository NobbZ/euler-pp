#include <cstdint>
#include <ranges>
#include <string>

#include "numbers.hpp"

#include "problem7.hpp"

REGISTER_EULER_PROBLEM(euler::problem7, 7, "10 001st Prime")

uint64_t euler::problem7::run() {
  // return *std::next(numbers::primes().begin(), 10000);
  auto prime = numbers::primes() | std::views::take(10001) | std::views::drop(10000);

  auto it = prime.begin();
  return *it;
}
