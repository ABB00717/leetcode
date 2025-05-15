#
# @lc app=leetcode id=2900 lang=python3
#
# [2900] Longest Unequal Adjacent Groups Subsequence I
#

# @lc code=start
from typing import List


class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        start = [0, 0]
        ans = [[], []]
        for i in range(n):
            if start[0] % 2 == 0 and groups[i] == 0 or start[0] % 2 == 1 and groups[i] == 1:
                start[0] += 1
                ans[0].append(words[i])
            if start[1] % 2 == 0 and groups[i] == 1 or start[1] % 2 == 1 and groups[i] == 0:
                start[1] += 1
                ans[1].append(words[i])

        return ans[0] if len(ans[0]) > len(ans[1]) else ans[1]


# @lc code=end

