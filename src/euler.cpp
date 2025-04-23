#include <sstream>

#include "euler.hpp"

const std::string BASE_URL = "https://projecteuler.net/";

std::string euler::euler::url() {
  std::ostringstream oss;

  oss << BASE_URL << "format=" << this->id();

  return oss.str();
}

std::map<int16_t, euler::euler *> euler::euler::problems = {};
