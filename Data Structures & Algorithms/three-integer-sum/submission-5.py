class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(len(nums)):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j = i+1 
            k=len(nums)-1
            while j<k:
                Tsum = nums[i] + nums[j] + nums[k]
                if Tsum > 0:
                    k-=1
                elif Tsum < 0:
                    j+=1
                else:
                    tmp = [nums[i],nums[j],nums[k]]
                    k-=1
                    j+=1
                    res.append(tmp)
                    while nums[j] == nums[j-1] and j<k:
                        j+=1
        return res
