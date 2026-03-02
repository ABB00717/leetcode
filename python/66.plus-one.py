from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        result = digits
        i = len(result) - 1
        while i != -1:
            if result[i] is not 9:
                result[i] += 1
                return result
            result[i] = 0
            i -= 1

        result.insert(0, 1)
        return result
