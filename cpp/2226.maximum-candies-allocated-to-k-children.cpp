/*
 * @lc app=leetcode id=2226 lang=cpp
 *
 * [2226] Maximum Candies Allocated to K Children
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
  int maximumCandies(std::vector<int> &candies, long long k) {
    int maximumCandies = 0;
    int l = 0, r = *std::max_element(candies.begin(), candies.end());

    while (l <= r) {
      int m = l + (r - l) / 2;
      long long int allocated = 0;

      if (m == 0) {
        l = m + 1;
        continue;
      }
      for (const int& candy : candies) {
        allocated += static_cast<int>(candy / m);
      }

      if (allocated >= k) {
        maximumCandies = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    return maximumCandies;
  }
};
// @lc code=end