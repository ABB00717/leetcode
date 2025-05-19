#
# @lc app=leetcode id=3024 lang=python3
#
# [3024] Type of Triangle
#

# @lc code=start
from typing import List

class Solution:
    def triangleType(self, nums: List[int]) -> str:
        nums.sort()

        if nums[0] + nums[1] <= nums[2]:
            return "none"
        
        if nums[0] == nums[1] == nums[2]:
            return "equilateral"
        
        if nums[0] == nums[1] or nums[1] == nums[2] or nums[0] == nums[2]:
            return "isosceles"
        
        return "scalene"
        
# @lc code=end

