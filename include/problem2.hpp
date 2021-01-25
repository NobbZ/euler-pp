#pragma once

#include <cinttypes>
#include <string>

#include "euler.hpp"

namespace euler {
class problem2 : public euler {
public:
  int16_t id();
  std::string caption();
  std::string description();
  uint64_t run();
};
} // namespace euler
