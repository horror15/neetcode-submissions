class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        length = 0
        numSet = set(nums)
        for num in nums:
            if (num-1) not in numSet:
                count=1 
                start=num
                while (start+1) in numSet:
                    count +=1
                    start +=1
                length = max(length, count)
        return length