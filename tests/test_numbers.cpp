#include "catch2/catch_test_macros.hpp"

#include "fibonacci.hpp"
#include "numbers.hpp"
#include "prime.hpp"
#include <cstdint>

TEST_CASE("Palindrome detection works correctly", "[numbers]") {
  REQUIRE(euler::numbers::is_palindrome(121) == true);
  REQUIRE(euler::numbers::is_palindrome(123) == false);
  REQUIRE(euler::numbers::is_palindrome(12321) == true);
  REQUIRE(euler::numbers::is_palindrome(12345) == false);
  REQUIRE(euler::numbers::is_palindrome(UINT16_C(121)) == true);
  REQUIRE(euler::numbers::is_palindrome(UINT16_C(123)) == false);
  REQUIRE(euler::numbers::is_palindrome(UINT16_C(12321)) == true);
  REQUIRE(euler::numbers::is_palindrome(UINT16_C(12345)) == false);
}

TEST_CASE("Fibonacci sequence generates correct values", "[numbers]") {
  auto fib = euler::numbers::fibonacci_sequence | std::views::take(10) | std::views::common;
  std::vector<uint64_t> expected = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
  
  REQUIRE(std::equal(fib.begin(), fib.end(), expected.begin()));
}

TEST_CASE("Prime sequence generates correct values", "[numbers]") {
  auto primes = euler::numbers::primes() | std::views::take(10) | std::ranges::to<std::vector>();
  std::vector<uint64_t> expected = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  
  REQUIRE(std::equal(primes.begin(), primes.end(), expected.begin()));
}

TEST_CASE("Transpose works correctly", "[numbers]") {
  std::array<std::array<int, 3>, 2> m = {{{1, 2, 3}, {4, 5, 6}}};
  std::array<std::array<int, 2>, 3> expected = {{{1, 4}, {2, 5}, {3, 6}}};

  REQUIRE(euler::numbers::transpose(m) == expected);
}
