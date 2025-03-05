/*
 * @lc app=leetcode id=2579 lang=cpp
 *
 * [2579] Count Total Number of Colored Cells
 */

// @lc code=start
#include <vector>
class Solution {
public:
  long long coloredCells(int n) {
    std::vector<long long> dp(n+1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i-1] + i*4 - 4;
    }

    return dp[n];
  }
};
// @lc code=end
