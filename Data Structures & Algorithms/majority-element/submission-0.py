class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        res = 0
        total = len(nums)/2

        for num in nums:
            if count == 0:
                res = num
            if res == num:
                count += 1
            else:
                count += -1
        return res