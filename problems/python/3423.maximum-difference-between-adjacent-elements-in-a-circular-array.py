#
# @lc app=leetcode id=3423 lang=python3
#
# [3423] Maximum Difference Between Adjacent Elements in a Circular Array
#

# @lc code=start
from typing import List


class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        max_diff = abs(nums[0] - nums[-1])
        for i in range(len(nums)-1):
            max_diff = max(max_diff, abs(nums[i] - nums[i+1]))
        return max_diff
# @lc code=end

