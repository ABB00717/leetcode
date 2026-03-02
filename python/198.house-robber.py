from typing import List


class Solution:
    # 2, 7, 9, 3, 1
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        result = 0
        dp = [0] * 100
        dp[0] = nums[0]
        dp[1] = nums[1]

        for house, money in enumerate(nums[2:], start=2):
            max_stole = 0
            for adj in range(house - 2, -1, -1):
                max_stole = max(max_stole, dp[adj])
            dp[house] = max_stole + money

        for num in dp:
            result = max(result, num)
        return result
