from typing import List
import functools, operator


class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        result = []

        def helper(accu: List[int]):
            if len(accu) == k:
                sum = 0
                for num in accu:
                    sum += num
                if sum == n:
                    result.append(accu)
                return

            for next in range(accu[-1] + 1, 10):
                helper(accu + [next])

        for next in range(1, 10):
            helper([next])
        return result
