#pragma once

#include <cinttypes>
#include <string>

namespace euler {

/** A virtual class to be used as a blueprint for actual euler problems
 *
 */
class euler {
public:
  /** This field shall return the actual ID of the problem. */
  virtual int16_t id() = 0;
  /** This field shall return the actual title of the problem. */
  virtual std::string caption() = 0;
  /** This field shall return a longer description of the problem. */
  virtual std::string description() = 0;

  /** Runs the actual problem solution and returns the result. */
  virtual uint64_t run() = 0;

  /** Returns the URL of the problem description on project eurler. */
  std::string url();
};
} // namespace euler
