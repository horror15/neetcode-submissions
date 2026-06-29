class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        pp = {}
        i = 0
        j=0
        ans = []
        for item in nums:
            pp[item] = i
            i = i+1
        for item in nums:
            diff = target - item
            if (diff in pp) and (pp[diff] != j):
               ans.append(pp[diff])
               ans.append(j)
               ans.sort()
               return ans
            else:
                j = j + 1

