#pragma once

#include <cstdint>
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

/** Checkes whether a given number is a palindrome.
 *
 * @param n the number to check
 * @return whether `n` is a palindrome
 */
bool is_palindrome(uint64_t const n) __attribute__((const));

/** A view on a infinite stream of fib numbers.
 *
 * @return a view on the infinite stream of fib numbers
 */
inline constexpr std::ranges::subrange<euler::numbers::fibonacci_iterator,
                                       std::unreachable_sentinel_t>
    fibonacci_sequence = std::ranges::subrange(
        euler::numbers::fibonacci_iterator{}, std::unreachable_sentinel);

inline constexpr std::array<uint64_t, 2> prefix{2, 3};

inline constexpr bool is_prime(uint64_t n) {
  if (n < 2) {
    return false;
  }

  if (n == 2 || n == 3) {
    return true;
  }

  for (uint64_t i = 5; i * i <= n; i += 6) {
    // We check for divisibility by 6k - 1 and 6k + 1
    // We know any prime number greater than 3 can be written in the form 6k ± 1
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Wswitch-default"
inline std::generator<uint64_t> primes() {
  for (auto p : prefix) {
    co_yield p;
  }

  for (uint64_t k : std::ranges::views::iota(UINT64_C(1))) {
    const uint64_t candidate_1 = 6 * k - 1;
    const uint64_t candidate_2 = 6 * k + 1;

    if (is_prime(candidate_1))
      co_yield candidate_1;

    if (is_prime(candidate_2))
      co_yield candidate_2;
  }
}
#pragma GCC diagnostic pop
} // namespace euler::numbers
