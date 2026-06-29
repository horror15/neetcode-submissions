class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        i,j=0,0
        mp = defaultdict(int)
        res = 0
        while(j<len(s)):
            mp[s[j]] += 1
            ch = max(mp, key=mp.get)
            print(ch)
            if ((j-i+1)-mp[ch]) <= k:
                res = max(res, j-i+1)
                j+=1
            else:
                while ((j-i+1)-mp[ch]) > k:
                    mp[s[i]]-=1
                    if mp[s[i]] == 0:
                        del mp[s[i]]
                    i+=1
                    ch = max(mp, key=mp.get)
                j+=1
        return res

            


