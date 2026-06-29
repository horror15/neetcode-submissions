class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        buy = prices[0]
        for i in range(1, len(prices)):
            if prices[i] < prices[i-1]:
                profit += (prices[i-1] - buy)
                buy = prices[i]
        if (buy != prices[len(prices)-1]):
            profit += prices[len(prices)-1] - buy
        return profit 