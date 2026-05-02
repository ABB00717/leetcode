from typing import List


class Solution:
    # len(nums) is expected to be equal to len(nums[i])
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        set = ()

        seen = [int(num, 2) for num in nums]

        # Base on Pigeonhole Principle, we only have to
        # enumerate until len(nums)+1 instead of limit(n)+1
        for num in range(n + 1):
            if num not in seen:
                return f"{num:0{n}b}"

        return ""
