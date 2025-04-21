#pragma once

#include "euler.hpp"

namespace euler {
class problem4 : public euler {
public:
  int16_t id();
  std::string caption();
  std::string description();
  uint64_t run();
};
} // namespace euler
