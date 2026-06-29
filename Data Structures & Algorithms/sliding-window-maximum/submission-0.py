class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        out = []
        mp = {}
        i,j=0,0
        count = 0
        while j < len(nums) or count==k:
            if count!=k:
                mp[j] = nums[j]
                j+=1
                count+=1
            else:
                val = max(mp.values())
                out.append(val)
                del mp[i]
                i+=1
                count-=1
        return out


