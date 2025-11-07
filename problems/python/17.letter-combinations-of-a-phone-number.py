from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        digit_to_letters = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        n = len(digits)

        def helper(i, comb):
            if i == n:
                result.append(comb)
                return

            dig = digits[i]
            for letter in digit_to_letters[dig]:
                helper(i + 1, comb + letter)

        result = []
        helper(0, "")

        return result


s = Solution()
print(s.letterCombinations("23"))
print(s.letterCombinations("2234"))
