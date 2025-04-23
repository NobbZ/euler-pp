#include "problem3.hpp"

static bool problem1_registered = euler::euler::register_problem<euler::problem3>();

int16_t euler::problem3::id() const { return 3; }

std::string euler::problem3::caption() { return "Largest Prime Factor"; }

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
