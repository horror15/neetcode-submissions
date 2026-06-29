class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        i,j=0,0
        mp1= {}
        mp2= {}
        if len(s1) > len(s2):
            return False
        for i in range(26):
            mp1[chr(ord('a')+i)] = 0
            mp2[chr(ord('a')+i)] = 0
        for i in range(len(s1)):
            mp1[s1[i]] += 1
            mp2[s2[i]] += 1
        matches = 0
        for i in range(26):
            char = chr(ord('a')+i)
            if mp1[char] == mp2[char]:
                matches += 1
        l=0
        for i in range(len(s1), len(s2)):
            if matches == 26:
                return True
            mp2[s2[i]]+=1
            if mp1[s2[i]] == mp2[s2[i]]:
                matches+=1
            elif mp1[s2[i]] + 1 == mp2[s2[i]]:
                matches-=1
            mp2[s2[l]]-=1
            if mp1[s2[l]] == mp2[s2[l]]:
                matches+=1
            elif mp1[s2[l]] - 1 == mp2[s2[l]]:
                matches-=1
            l+=1
        return matches==26

        