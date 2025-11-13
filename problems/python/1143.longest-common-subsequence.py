class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m = len(text2)
        n = len(text1)
        dp = [[0 for _ in range(n)] for _ in range(m)]

        for i2, t2_c in enumerate(text2):
            for i1, t1_c in enumerate(text1):
                up = dp[i2 - 1][i1] if i2 != 0 else 0
                left = dp[i2][i1 - 1] if i1 != 0 else 0

                cur_max = max(up, left)

                if t2_c == t1_c:
                    diagonal = dp[i2 - 1][i1 - 1] if i1 != 0 and i2 != 0 else 0
                    dp[i2][i1] = diagonal + 1
                else:
                    dp[i2][i1] = cur_max

        return dp[m - 1][n - 1]
