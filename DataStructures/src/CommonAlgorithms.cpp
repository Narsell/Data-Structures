#include "CommonAlgorithms.h"


const uint64_t rFibonacci(const int n, std::vector<uint64_t>& memo, int& counter)
{
    ++counter;

    if (memo[n] != -1) return memo[n];

    if (n == 1 || n == 0) return n;

    memo[n] = rFibonacci(n - 1, memo, counter) + rFibonacci(n - 2, memo, counter);
    return memo[n];
}

const uint64_t iFibonacci(const int n, int& counter)
{

    uint64_t* fib = new uint64_t[n + 1];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        ++counter;
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    uint64_t value = fib[n];

    delete[] fib;

    return value;
}
