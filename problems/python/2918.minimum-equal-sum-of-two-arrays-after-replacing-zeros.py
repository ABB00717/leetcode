#
# @lc app=leetcode id=2918 lang=python3
#
# [2918] Minimum Equal Sum of Two Arrays After Replacing Zeros
#

# @lc code=start
class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        sum1, sum2 = sum(nums1), sum(nums2)

        zeros1, zeros2 = nums1.count(0), nums2.count(0)

        if (sum1 + zeros1 > sum2 and zeros2 == 0 or sum2 + zeros2 > sum1 and zeros1 == 0):
            return -1

        return max(sum1 + zeros1, sum2 + zeros2)
# @lc code=end

