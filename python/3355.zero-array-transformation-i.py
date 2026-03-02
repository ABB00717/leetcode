#
# @lc app=leetcode id=3355 lang=python3
#
# [3355] Zero Array Transformation I
#

# @lc code=start
from typing import List

class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        prefix_sum = [0] * (len(nums) + 1)

        for start, end in queries:
            prefix_sum[start] += 1
            prefix_sum[end + 1] -= 1

        current_sum = 0
        for i in range(len(nums)):
            current_sum -= prefix_sum[i]
            nums[i] += max(-nums[i], current_sum)

        return all(num == 0 for num in nums)

# @lc code=end

