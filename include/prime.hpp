#pragma once

#include <array>
#include <cstdint>
#include <generator>

namespace euler::numbers {

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

}
