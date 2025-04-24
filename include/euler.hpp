#pragma once

#include <cstdint>
#include <map>
#include <ranges>
#include <string>
#include <vector>

namespace euler {

/** A virtual class to be used as a blueprint for actual euler problems
 *
 */
class [[gnu::abi_tag("cxx11")]] euler {
public:
  virtual ~euler() = default;

  /** This field shall return the actual ID of the problem. */
  virtual int16_t id() const = 0;
  /** This field shall return the actual title of the problem. */
  virtual std::string caption() = 0;

  /** Runs the actual problem solution and returns the result. */
  virtual uint64_t run() = 0;

  /** Returns the URL of the problem description on project eurler. */
  std::string url();

  /** returns the list of all registered problems */
  static std::vector<euler *> registry() {
    auto ps = std::ranges::views::values(problems);
    return std::vector<euler *>(ps.begin(), ps.end());
  }

  /** returns the problem with the given id */
  static euler *get_problem(int16_t id) {
    return problems.at(id);
  }

  /** registers a problem implementation */
  template <typename T> static bool register_problem() {
    auto problem = new T();
    problems.insert({problem->id(), problem});
    return true;
  }

private:
  static std::map<int16_t, euler*> problems;
};

#define REGISTER_EULER_PROBLEM(ProblemClass, ProblemId, ProblemCaption) \
  namespace { \
    static bool problem##ProblemId##_registered = euler::euler::register_problem<ProblemClass>(); \
  } \
  \
  int16_t ProblemClass::id() const { return ProblemId; } \
  \
  std::string ProblemClass::caption() { return ProblemCaption; }

} // namespace euler
