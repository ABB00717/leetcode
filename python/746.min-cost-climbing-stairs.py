from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [-1] * n
        dp[0] = cost[0]
        dp[1] = cost[1]

        # Fill the dp from top
        def helper(i):
            if dp[i] != -1:
                return
            if dp[i - 1] == -1:
                helper(i - 1)
            if dp[i - 2] == -1:
                helper(i - 2)

            min_cost = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i])
            dp[i] = min_cost

        helper(n - 1)

        return min(dp[n - 1], dp[n - 2])
