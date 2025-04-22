#include "problem2.hpp"

const uint64_t UPPER_BOUND = 4000000; 

int16_t euler::problem2::id() const { return 2; }

std::string euler::problem2::caption() { return "Even Fibonacci numbers"; }

uint64_t euler::problem2::run() {
  uint64_t sum{0};
  uint64_t i{1}, j{1};
  uint64_t fib { i + j };

  while (fib < UPPER_BOUND) {
    if (fib % 2 == 0) sum += fib;

    i = j;
    j = fib;
    fib = i + j;
  }

  return sum;
}
