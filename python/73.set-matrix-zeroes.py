#
# @lc app=leetcode id=73 lang=python3
#
# [73] Set Matrix Zeroes
#

# @lc code=start
from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        row_to_be_zero = set()
        col_to_be_zero = set()

        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    row_to_be_zero.add(i)
                    col_to_be_zero.add(j)
        
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if i in row_to_be_zero or j in col_to_be_zero:
                    matrix[i][j] = 0
        
# @lc code=end

