from typing import List


class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        # Calculate initial F(0) and the total sum of elements.
        # F(0) = 0 * nums[0] + 1 * nums[1] + ... + (n-1) * nums[n-1]
        # F(k) = F(k-1) + sum(nums) - n * nums[n-k]

        n = len(nums)
        if n == 0:
            return 0

        total_sum = sum(nums)
        f = sum(i * val for i, val in enumerate(nums))
        max_f = f

        for k in range(1, n):
            # Update F(k) based on F(k-1)
            # The last element in the previous rotation moves to the first position,
            # its coefficient changes from (n-1) to 0. All other elements' coefficients increase by 1.
            f += total_sum - n * nums[n - k]
            max_f = max(max_f, f)

        return max_f
