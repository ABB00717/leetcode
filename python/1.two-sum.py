#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#
# @lc code=start
from ast import List

class Solution: 
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for i, num in enumerate(nums):
            com = target - num
            if com in map:
                return [map[com], i]
            
            map[num] = i
            
        return []
        
# @lc code=end

