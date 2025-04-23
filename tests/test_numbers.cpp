#include "catch2/catch_test_macros.hpp"
#include "numbers.hpp"

TEST_CASE("Palindrome detection works correctly", "[numbers]") {
  REQUIRE(euler::numbers::is_palindrome(121) == true);
  REQUIRE(euler::numbers::is_palindrome(123) == false);
  REQUIRE(euler::numbers::is_palindrome(12321) == true);
  REQUIRE(euler::numbers::is_palindrome(12345) == false);
}

TEST_CASE("Fibonacci sequence generates correct values", "[numbers]") {
  auto fib = euler::numbers::fibonacci_sequence | std::views::take(10) | std::views::common;
  std::vector<uint64_t> expected = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
  
  REQUIRE(std::equal(fib.begin(), fib.end(), expected.begin()));
}
