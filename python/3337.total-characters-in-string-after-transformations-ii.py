#
# @lc app=leetcode id=3337 lang=python3
#
# [3337] Total Characters in String After Transformations II
#

# @lc code=start
from typing import List
import collections

MOD = 10**9 + 7
ALPHABET_SIZE = 26

class Mat:
    def __init__(self, copy_from: "Mat" = None, identity: bool = False) -> None:
        self.a: List[List[int]] = [[0] * ALPHABET_SIZE for _ in range(ALPHABET_SIZE)]
        if copy_from:
            for i in range(ALPHABET_SIZE):
                for j in range(ALPHABET_SIZE):
                    self.a[i][j] = copy_from.a[i][j]
        if identity:
            for i in range(ALPHABET_SIZE):
                self.a[i][i] = 1


    def __mul__(self, other: "Mat") -> "Mat":
        res = Mat()
        for i in range(ALPHABET_SIZE):
            for j in range(ALPHABET_SIZE):
                for k in range(ALPHABET_SIZE):
                    res.a[i][j] = (res.a[i][j] + self.a[i][k] * other.a[k][j]) % MOD
        return res

def quickmul(x: Mat, y: int) -> Mat:
    ans = Mat(identity=True)
    while y:
        if y & 1:
            ans = ans * x
        x = x * x
        y >>= 1
    return ans

class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        M = Mat()
        for i in range(ALPHABET_SIZE):
            for j in range(1, nums[i] + 1):
                M.a[(i + j) % ALPHABET_SIZE][i] += 1
        
        M_t = quickmul(M, t)

        f = [0] * ALPHABET_SIZE
        for ch in s:
            f[ord(ch) - ord('a')] += 1

        ans = 0
        for i in range(ALPHABET_SIZE):
            for j in range(ALPHABET_SIZE):
                ans = (ans + M_t.a[i][j] * f[j]) % MOD
        
        return ans

# @lc code=end

