class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        s = s + s

        target1, target2 = "", ""
        for i in range(len(s)):
            target1 += "1" if i % 2 == 0 else "0"
            target2 += "0" if i % 2 == 0 else "1"

        ans = float("inf")
        diff1, diff2 = 0, 0
        l = 0
        for r in range(len(s)):
            if s[r] != target1[r]:
                diff1 += 1
            if s[r] != target2[r]:
                diff2 += 1

            if (r - l + 1) > n:
                if s[l] != target1[l]:
                    diff1 -= 1
                if s[l] != target2[l]:
                    diff2 -= 1

                l += 1

            if (r - l + 1) == n:
                ans = min(ans, diff1, diff2)

        return ans
