class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        buy = prices[0]

        for i in range(1,len(prices)):
            if prices [i] > buy:
                profit = prices[i] - buy
                maxprofit = max(profit, maxprofit) 
            else:
                buy = min(buy, prices[i])
        return maxprofit
            