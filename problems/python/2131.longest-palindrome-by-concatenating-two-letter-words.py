#
# @lc app=leetcode id=2131 lang=python3
#
# [2131] Longest Palindrome by Concatenating Two Letter Words
#

# @lc code=start
from typing import List


class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        dict = {}
        same_words = {}
        result = 0
        for word in words:
            if word == word[::-1]:
                if word not in same_words:
                    same_words[word] = 0
                same_words[word] += 1
            elif word != word[::-1] and word[::-1] in dict and dict[word[::-1]] > 0:
                dict[word[::-1]] -= 1
                result += 4
            else:
                if word not in dict:
                    dict[word] = 0
                dict[word] += 1
        
        print(same_words)
        print(dict)
        
        odd_count = False
        for word, count in same_words.items():
            if count % 2 == 0:
                result += count * 2
            else:
                if not odd_count:
                    result += count * 2
                    odd_count = True
                else:
                    result += (count - 1) * 2

        return result
            

# @lc code=end

