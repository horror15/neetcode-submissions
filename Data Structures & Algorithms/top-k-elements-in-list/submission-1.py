class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = []
        for i in range(len(nums)+1):
            freq.append([])
        count = {}
        for num in nums:
            if num in count:
                count[num] = count[num] + 1
            else:
                count[num] = 1
        for key,value in count.items():
            freq[value].append(key)
        res = []
        for i in range(len(freq)-1, 0, -1):
            for num in freq[i]:
                res.append(num)
                if len(res) == k:
                    return res
