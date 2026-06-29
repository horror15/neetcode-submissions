class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = defaultdict(int)
        maxl=0
        i,j=0,0

        while(j<len(s)):
            mp[s[j]] += 1
            if len(mp) == j-i+1:
                j+=1
            else:
                maxl = max(maxl, len(mp))
                while len(mp) != j-i+1:
                    mp[s[i]] -= 1
                    if mp[s[i]] == 0:
                        del mp[s[i]]
                    i+=1
                j+=1

        return max(maxl,len(mp))