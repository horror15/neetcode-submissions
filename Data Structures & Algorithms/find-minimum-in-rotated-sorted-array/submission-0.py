class Solution:
    def findMin(self, nums: List[int]) -> int:
        i,j=0,len(nums)-1
        mini = 1000
        while i<=j:
            mid = (i+j)//2
            if nums[mid] > nums[j]:
                i = mid+1
            else:
                mini = min(mini,nums[mid])
                j = mid-1
        return mini
