#
# @lc app=leetcode id=1007 lang=python3
#
# [1007] Minimum Domino Rotations For Equal Row
#

# @lc code=start
from typing import List


class Solution:

    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        n = len(tops)

        for target in (tops[0], bottoms[0]):
            is_possible = True
            
            for i in range(n):
                if tops[i] != target and bottoms[i] != target:
                    is_possible = False
                    break
            
            if is_possible:
                return min(sum(tops[i] != target for i in range(n)),
                           sum(bottoms[i] != target for i in range(n)))
        
        return -1


# @lc code=end
