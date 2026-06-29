class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def can_split(mid):
            s = 0
            count = 0
            for num in nums:          
                if s+num > mid:
                    count+=1
                    s = 0
                s+=num
            if s <= mid:
                count+=1
            if count <= k:
                return True
            else:
                return False    
                
        i = max(nums)
        j = sum(nums)
        output = 0
        while i<=j:
            mid = (i+j)//2
            if can_split(mid):
                output = mid
                j = mid-1
            else:
                i = mid+1
        return output
