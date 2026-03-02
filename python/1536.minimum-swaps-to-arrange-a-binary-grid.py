from typing import List


class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)
        trailing_zeros = []
        for row in grid:
            count = 0
            for i in range(n - 1, -1, -1):
                if row[i] == 0:
                    count += 1
                else:
                    break
            trailing_zeros.append(count)

        res = 0
        for i in range(n):
            target = n - 1 - i

            found = -1
            for j in range(i, n):
                # If amount of trailing zero is already bigger than
                # the requirement right here, then there's no fit in
                # place for it already. So break the loop
                if trailing_zeros[j] >= target:
                    found = j
                    break

            if found == -1:
                return -1

            # Since only adjacent row can be swapped
            res += found - i
            val = trailing_zeros.pop(found)
            trailing_zeros.insert(i, val)

        return res
