#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

int f_if(int) __attribute__((const));
int f_bitwise(int) __attribute__((const));
int f_arithmetic(int) __attribute__((const));
int f_conditional(int) __attribute__((const));

// Original implementation
int f_if(int n) {
    if (n % 2 == 0) return -1;
    return 1;
}

// Bitwise implementation
int f_bitwise(int n) {
    return 1 - 2 * ((n & 1) ^ 1);
}

// Arithmetic implementation
int f_arithmetic(int n) {
    return (n % 2) * 2 - 1;
}

// Conditional expression
int f_conditional(int n) {
    return (n % 2 == 0) ? -1 : 1;
}

TEST_CASE("Function correctness") {
    REQUIRE(f_if(0) == -1);
    REQUIRE(f_if(1) == 1);
    REQUIRE(f_if(2) == -1);
    REQUIRE(f_if(3) == 1);

    REQUIRE(f_bitwise(0) == -1);
    REQUIRE(f_bitwise(1) == 1);
    REQUIRE(f_bitwise(2) == -1);
    REQUIRE(f_bitwise(3) == 1);

    REQUIRE(f_arithmetic(0) == -1);
    REQUIRE(f_arithmetic(1) == 1);
    REQUIRE(f_arithmetic(2) == -1);
    REQUIRE(f_arithmetic(3) == 1);

    REQUIRE(f_conditional(0) == -1);
    REQUIRE(f_conditional(1) == 1);
    REQUIRE(f_conditional(2) == -1);
    REQUIRE(f_conditional(3) == 1);
}

TEST_CASE("Performance comparison") {
    constexpr int test_size = 1'000'000;
    std::vector<int> input;
    input.reserve(test_size);
    
    // Generate alternating even/odd inputs
    for (int i = 0; i < test_size; ++i) {
        input.push_back(i);
    }

    SECTION("Benchmarking different implementations for the flip_one function") {
        BENCHMARK("if-statement") {
            int result = 0;
            for (int n : input) {
                result += f_if(n);
            }
            return result;
        };
        BENCHMARK("bitwise") {
            int result = 0;
            for (int n : input) {
                result += f_bitwise(n);
            }
            return result;
        };
        BENCHMARK("arithmetic") {
            int result = 0;
            for (int n : input) {
                result += f_arithmetic(n);
            }
            return result;
        };
        BENCHMARK("conditional") {
            int result = 0;
            for (int n : input) {
                result += f_conditional(n);
            }
            return result;
        };
    }
}
