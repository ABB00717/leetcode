/*
 * @lc app=leetcode id=2523 lang=cpp
 *
 * [2523] Closest Prime Numbers in Range
 */

// @lc code=start
#include <climits>
#include <cmath>
#include <vector>
class Solution {
private:
  bool isPrime(int num) {
    if (num == 2)
      return true;
    if (num < 2 || num % 2 == 0)
      return false;

    int upBound = std::sqrt(num);
    for (int i = 3; i <= upBound; i += 2) {
      if (num % i == 0)
        return false;
    }

    return true;
  }

public:
  std::vector<int> closestPrimes(int left, int right) {
    std::vector<int> primeNumbers;

    std::vector<int> result = {-1, -1};
    int min = INT_MAX;
    for (int i = left; i <= right; i++) {
      if (isPrime(i)) {
        primeNumbers.push_back(i);
        if (primeNumbers.size() > 1) {
          int n = primeNumbers.size();
          int a = primeNumbers[n-2], b = primeNumbers[n-1];
  
          if (b - a < min) {
            result = {a, b};
            min = b - a;
          }
        }

        if (min == 2)
          return result;
      }
    }

    return result;
  }
};
// @lc code=end
