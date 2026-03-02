#
# @lc app=leetcode id=2894 lang=python3
#
# [2894] Divisible and Non-divisible Sums Difference
#

# @lc code=start
class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        num1 = 0
        num2 = 0

        for num in range(1, n + 1):
            if num % m != 0:
                num1 += num
            else:
                num2 += num

        return num1 - num2
# @lc code=end

