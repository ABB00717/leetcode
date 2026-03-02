#
# @lc app=leetcode id=3335 lang=python3
#
# [3335] Total Characters in String After Transformations I
#

# @lc code=start
class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1

        for _ in range(t):
            countOfZ = count[25]
            count.insert(0, 0)
            count[0] += countOfZ
            count[1] += countOfZ
            count.pop()
        
        return sum(count) % 1000000007
            

# @lc code=end

