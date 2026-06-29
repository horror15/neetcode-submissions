class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i,j=0, len(nums)-1
        while i<j:
            mid = (i+j)//2
            if nums[mid] > nums[j]:
                i = mid+1
            else:
                j=mid

        if nums[i] <= target and nums[len(nums)-1] >=target:
            j = len(nums)-1
        else:
            j,i = i-1,0
        while i<=j:
            mid = (i+j)//2
            if nums[mid] > target:
                j = mid-1
            elif nums[mid] < target:
                i = mid+1
            else:
                return mid
        return -1

