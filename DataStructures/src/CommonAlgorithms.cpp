#include "CommonAlgorithms.h"


const int rFibonacci(const int n, std::vector<int>& memo, int& counter)
{
    ++counter;

    if (memo[n] != -1) return memo[n];

    if (n == 1 || n == 0) return n;

    memo[n] = rFibonacci(n - 1, memo, counter) + rFibonacci(n - 2, memo, counter);
    return memo[n];
}

const int iFibonnacci(const int n)
{
    return 0;
}
