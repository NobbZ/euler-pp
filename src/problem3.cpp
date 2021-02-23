#include "problem3.hpp"

int16_t euler::problem3::id() { return 3; }

std::string euler::problem3::caption() { return "Largest Prime Factor"; }

std::string euler::problem3::description() {
  return "The prime factors of 131955 are 5, 7, 13, and 29.\n"
         "\n"
         "What is the largest prime factor of the number 600851475143?\n";
}

uint64_t euler::problem3::run() {
  uint64_t num { 600851475143 };
  uint64_t i { 2 };

  while (i * i < num) {
    if (num % i == 0) {
      num /= i;
    } else {
      i++;
    }
  }

  return num;
}
