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
} // namespace euler::numbers
