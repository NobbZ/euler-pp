#include <catch2/catch_test_macros.hpp>
#include "problem1.hpp"
#include "problem2.hpp"
#include "problem3.hpp"
#include "problem4.hpp"
#include "problem5.hpp"
#include "problem6.hpp"
#include "problem7.hpp"
#include "problem8.hpp"
#include "problem9.hpp"

TEST_CASE("Problem 1 returns correct result", "[problems]") {
  euler::problem1 p1;
  REQUIRE(p1.run() == 233168);
}

TEST_CASE("Problem 2 returns correct result", "[problems]") {
  euler::problem2 p2;
  REQUIRE(p2.run() == 4613732);
}

TEST_CASE("Problem 3 returns correct result", "[problems]") {
  euler::problem3 p3;
  REQUIRE(p3.run() == 6857);
}

TEST_CASE("Problem 4 returns correct result", "[problems]") {
  euler::problem4 p4;
  REQUIRE(p4.run() == 906609);
}

TEST_CASE("Problem 5 returns correct result", "[problems]") {
  euler::problem5 p5;
  REQUIRE(p5.run() == 232792560);
}

TEST_CASE("Problem 6 returns correct result", "[problems]") {
  euler::problem6 p6;
  REQUIRE(p6.run() == 25164150);
}

TEST_CASE("Problem 7 returns correct result", "[problems]") {
  euler::problem7 p7;
  REQUIRE(p7.run() == 104743);
}

TEST_CASE("Problem 8 returns correct result", "[problems]") {
  euler::problem8 p8;
  REQUIRE(p8.run() == 23514624000);
}

TEST_CASE("Problem 9 returns correct result", "[problems]") {
  euler::problem9 p9;
  REQUIRE(p9.run() == 31875000);
}
