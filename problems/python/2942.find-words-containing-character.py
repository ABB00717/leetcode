#
# @lc app=leetcode id=2942 lang=python3
#
# [2942] Find Words Containing Character
#

# @lc code=start
from typing import List

class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        return [i for i, word in enumerate(words) if x in word]
# @lc code=end

