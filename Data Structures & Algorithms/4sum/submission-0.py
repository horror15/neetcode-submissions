class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        output = []
        nums.sort()
        for i in range(len(nums)):
            if nums[i] == nums[i-1] and i>0:
                continue
            for j in range(i+1, len(nums)):
                #print("hello")
                if nums[j] == nums[j-1] and j>i+1:
                    continue
                left = j+1
                right = len(nums)-1
                while left<right:
                        #print("hello")
                    sum = nums[i]+nums[j]+nums[left]+nums[right]
                    if sum < target:
                        left += 1
                    elif sum > target:
                        right -= 1
                    else:
                        output.append([nums[i],nums[j],nums[left],nums[right]])
                        left += 1
                        right -= 1
                        while nums[left] == nums[left-1] and left < right:
                            left += 1
                        while nums[right] == nums[right+1] and left<right:
                            right -= 1
        return output