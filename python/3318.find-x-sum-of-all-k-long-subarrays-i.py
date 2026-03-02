from typing import List


class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        result = []
        n = len(nums)

        # slide through L
        for i in range(n - k + 1):
            l = i
            r = i + k
            count = {}
            for slide in range(l, r):
                num = nums[slide]
                if not count.get(num):
                    count[num] = 1
                else:
                    count[num] += 1

            t = list(count.items())
            t.sort(key=lambda x: (-x[1], -x[0]))

            num = 0
            for it in t[:x]:
                num += it[0] * it[1]

            result.append(num)

        return result


nums = [1, 1, 2, 2, 3, 4, 2, 3]
k = 6
x = 2
s = Solution()
print(s.findXSum(nums, k, 2))
