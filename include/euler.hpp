#pragma once

#include <cinttypes>
#include <string>

namespace euler {
class euler {
public:
  virtual int16_t id() = 0;
  virtual std::string caption() = 0;
  virtual std::string description() = 0;

  virtual uint64_t run() = 0;
};
} // namespace euler
