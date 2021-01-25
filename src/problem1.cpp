#include "problem1.hpp"

int16_t euler::problem1::id() { return 1; }

std::string euler::problem1::caption() { return "Multiples of 3 and 5"; }

std::string euler::problem1::description() {
  return "If we list all the natural numbers below 10 that are multiples of 3 "
         "\n"
         "or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.\n"
         "\n"
         "Find the sum of all the multiples of 3 or 5 below 1000.\n";
}

uint64_t euler::problem1::run() {
  uint64_t sum{0};

  for (uint16_t i = 1; i < 1000; ++i) {
    if (i % 3 == 0 || i % 5 == 0) {
      sum += i;
    }
  }

  return sum;
}
