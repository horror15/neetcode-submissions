class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        i = 1
        j = max(piles)
        k=j
        while i <= j:
            mid  = (i+j)//2
            hours = 0
            for pile in piles:
                div = pile//mid
                rem = pile%mid
                if rem:
                    hours += div + 1
                else:
                    hours += div
            if hours > h:
                i = mid+1
            else:
                j = mid-1
                k = min(k, mid)
        return k
            
