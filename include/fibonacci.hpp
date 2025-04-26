#pragma once

#include <ranges>
#include <tuple>
#include <generator>

namespace euler::numbers {

struct fibonacci_iterator {
  uint64_t a = 0;
  uint64_t b = 1;

  friend constexpr bool
  operator==(const fibonacci_iterator &,
             const fibonacci_iterator &) noexcept = default;
  constexpr uint64_t operator*() const noexcept { return a; }
  constexpr fibonacci_iterator &operator++() noexcept {
    std::tie(a, b) = std::make_tuple(b, a + b);
    return *this;
  }
  constexpr fibonacci_iterator operator++(int) noexcept {
    auto tmp = *this;
    ++(*this);
    return tmp;
  }
  constexpr fibonacci_iterator &operator--() noexcept {
    std::tie(a, b) = std::make_tuple(b - a, a);
    return *this;
  }
  constexpr fibonacci_iterator operator--(int) noexcept {
    auto tmp = *this;
    --(*this);
    return tmp;
  }
  using value_type = uint64_t;
  using difference_type = std::ptrdiff_t;
};

/** A view on a infinite stream of fib numbers.
 *
 * @return a view on the infinite stream of fib numbers
 */
inline constexpr std::ranges::subrange<euler::numbers::fibonacci_iterator,
                                       std::unreachable_sentinel_t>
    fibonacci_sequence = std::ranges::subrange(
        euler::numbers::fibonacci_iterator{}, std::unreachable_sentinel);
}
