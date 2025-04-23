#include <cstdint>
#include <string>

#include "numbers.hpp"

#include "problem7.hpp"

REGISTER_EULER_PROBLEM(euler::problem7, 7, "10 001st Prime")

uint64_t euler::problem7::run() {
  return *std::next(numbers::prime_sequence.begin(), 10000);
}
