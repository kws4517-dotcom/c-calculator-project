#include <stdio.h>
#include "calc.h"

static int total_tests = 0;
static int passed_tests = 0;

void assert_equal(const char *test_name, int expected, int actual) {
    total_tests++;
    if (expected == actual) {
        passed_tests++;
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s: expected=%d, actual=%d\n", test_name, expected, actual);
    }
}

void assert_true(const char *test_name, int condition) {
    total_tests++;
    if (condition) {
        passed_tests++;
        printf("[PASS] %s\n", test_name);
    } else {
        printf("[FAIL] %s\n", test_name);
    }
}

int main(void) {
    int result = 0;

    assert_equal("add(10, 5)", 15, add(10, 5));
    assert_equal("sub(10, 5)", 5, sub(10, 5));
    assert_equal("mul(10, 5)", 50, mul(10, 5));

    assert_true("divide(10, 5) returns success", divide(10, 5, &result) == 1);
    assert_equal("divide result is 2", 2, result);

    assert_true("divide(10, 0) returns failure", divide(10, 0, &result) == 0);

    printf("\nTests passed: %d/%d\n", passed_tests, total_tests);

    return (passed_tests == total_tests) ? 0 : 1;
}

