#include "euler.hpp"

#include "problem3.hpp"

REGISTER_EULER_PROBLEM(euler::problem3, 3, "Largest Prime Factor");

uint64_t euler::problem3::run() {
  uint64_t num{600851475143};
  uint64_t i{2};

  while (i * i < num) {
    if (num % i == 0) {
      num /= i;
    } else {
      i++;
    }
  }

  return num;
}
