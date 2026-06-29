class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        i = max(weights)
        j = sum(weights)
        cap = 0
        while i<=j:
            mid  = (i+j)//2
            s = 0
            day = 1
            for w in weights:
                if s+w > mid:
                    day+=1
                    s = 0
                s+=w
            if day <= days:
                j = mid-1
                cap = mid
            else:
                i = mid+1
        return cap