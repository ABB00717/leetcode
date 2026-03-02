from typing import List


class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        cash = 0
        hold = -prices[0]
        n = len(prices)

        for i in range(n):
            prev_cash = cash
            cash = max(cash, hold + prices[i] - fee)
            hold = max(hold, prev_cash - prices[i])

        return cash
