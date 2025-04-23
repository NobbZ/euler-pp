#include <cstdint>
#include <string>

#include "numbers.hpp"

#include "problem7.hpp"

int16_t euler::problem7::id() const { return 7; }

std::string euler::problem7::caption() { return "10 001st Prime"; }

uint64_t euler::problem7::run() {
  return *std::next(numbers::prime_sequence.begin(), 10000);
}

