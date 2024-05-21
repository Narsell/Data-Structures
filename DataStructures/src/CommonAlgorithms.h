#pragma once
#include <vector>

/**
 * O(n) time complexity thanks to memoization.
 */
const uint64_t rFibonacci(const int n, std::vector<uint64_t>& memmo, int& counter);

/**
 * O(n) time complexity.
 */
const uint64_t iFibonacci(const int n, int& counter);