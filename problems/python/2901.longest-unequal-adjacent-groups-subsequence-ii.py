#
# @lc app=leetcode id=2901 lang=python3
#
# [2901] Longest Unequal Adjacent Groups Subsequence II
#

# @lc code=start
from typing import List

def hamming_distance(word1: str, word2: str) -> int:
    if len(word1) != len(word2):
        return -1

    return sum(1 for a, b in zip(word1, word2) if a != b)

class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)

        result = []
        dp = [[] for _ in range(n)]
        for i in range(n):
            longest = []
            for j in range(i):
                if groups[i] != groups[j] and hamming_distance(words[i], words[j]) == 1:
                    longest = max(longest, dp[j], key=len)
            dp[i] = longest + [words[i]]
            result = max(result, dp[i], key=len)
        return result

# @lc code=end

