#pragma once

#include "euler.hpp"

namespace euler {
class [[gnu::abi_tag("cxx11")]] problem6 : public euler {
public:
  int16_t id() const override __attribute__((const));
  std::string caption() override;
  uint64_t run() override __attribute__((const));
};
} // namespace euler
