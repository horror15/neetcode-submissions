class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)

        for ch in strs:
            count = [0]*26
            for c in ch:
                count[ord(c) - ord("a")] += 1
            res[tuple(count)].append(ch)
        #print(res.values())
        return list(res.values())







