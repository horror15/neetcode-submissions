class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ""
        for i in range(len(strs[0])):
            for items in strs:
                if i==len(items) or items[i] != strs[0][i]:
                    return res
            res = res + strs[0][i]
        return res