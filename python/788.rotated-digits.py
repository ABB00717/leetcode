class Solution:
    def rotatedDigits(self, n: int) -> int:
        result = 0
        for num in range(1, n + 1):
            # '\0' represent end of string
            s = str(num) + "\0"

            # If the number remain unchanged after switching
            diff = False
            for c in s:
                if c in ["0", "1", "8"]:
                    continue
                elif c in ["2", "5", "6", "9"]:
                    diff = True
                    continue
                elif c == "\0" and diff:
                    result += 1

                break

        return result
