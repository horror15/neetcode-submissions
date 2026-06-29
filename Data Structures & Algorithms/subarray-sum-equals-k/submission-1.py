class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        curr_sum = res = 0
        prefix = {}
        for num in nums:
            curr_sum += num
            if((curr_sum-k) == 0):
                res += 1
            if ((curr_sum - k) in prefix):
                res += prefix[curr_sum-k]
            if curr_sum in prefix:
                prefix[curr_sum] += 1
            else:
                prefix[curr_sum] = 1
        return res
