#
# @lc app=leetcode id=790 lang=python3
#
# [790] Domino and Tromino Tiling
#

# @lc code=start
class Solution:
    def numTilings(self, n: int) -> int:
        dp = [0] * (n + 1)
        
        if n == 1:
            return 1
        if n == 2:
            return 2
        
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % (10**9 + 7)
        
        return dp[n]
        
# @lc code=end

