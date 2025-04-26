#pragma once

#include <cstddef>
#include <generator>

namespace euler::numbers {
/** Checkes whether a given number is a palindrome.
 *
 * @param n the number to check
 * @return whether `n` is a palindrome
 */
template <typename T> bool is_palindrome(T const n) {
  T rev = 0;

  T tmp = n;
  while (tmp != 0) {
    rev = (rev * 10) + (tmp % 10);
    tmp /= 10;
  }

  return rev == n;
}

template <typename T, std::size_t x, std::size_t y>
constexpr std::array<std::array<T, y>, x>
transpose(std::array<std::array<T, x>, y> const &m) {
  std::array<std::array<T, y>, x> result;

  for (std::size_t i = 0; i < x; ++i) {
    for (std::size_t j = 0; j < y; ++j) {
      result[i][j] = m[j][i];
    }
  }

  return result;
}
} // namespace euler::numbers
