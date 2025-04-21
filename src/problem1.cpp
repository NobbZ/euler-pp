#include "problem1.hpp"

int16_t euler::problem1::id() { return 1; }

std::string euler::problem1::caption() { return "Multiples of 3 and 5"; }

uint64_t euler::problem1::run() {
  uint64_t sum{0};

  for (uint16_t i = 1; i < 1000; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }

  return sum;
}
