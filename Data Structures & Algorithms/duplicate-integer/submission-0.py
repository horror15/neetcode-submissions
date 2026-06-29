class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dup = []
        for value in nums:
            #print (value)
            if value not in dup:
                dup.append(value)
            else:
                return True
        return False
                

        