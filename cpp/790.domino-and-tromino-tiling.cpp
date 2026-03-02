/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
#include <vector>
class Solution {
   public:
    int numTilings(int n) {
        std::vector<int> dp(n + 1, 0);
        if (n == 1) return 1;
        if (n == 2) return 2;

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = ((long long)2 * dp[i - 1] + dp[i - 3]) % 1000000007;
        }

        return dp[n];
    }
};

// @lc code=end
