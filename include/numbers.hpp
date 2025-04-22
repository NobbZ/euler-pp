#pragma once

#include <cstdint>

namespace euler::numbers {

/** Checkes whether a given number is a palindrome.
 *
 * @param n the number to check
 * @return whether `n` is a palindrome
 */
bool is_palindrome(uint64_t const n) __attribute__((const));

} // namespace euler::numbers
