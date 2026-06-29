class Solution:
    def minWindow(self, s: str, t: str) -> str:
        mp2=defaultdict(int)
        string = ""
        for i in range(len(t)):
            mp2[t[i]]+=1
        count=len(mp2)
        i,j=0,0
        lenght=float("infinity")
        while j<len(s) or count == 0:
            print("hello")
            if count!=0:
                if s[j] in mp2:
                    mp2[s[j]]-=1
                    if mp2[s[j]] == 0:
                        count-=1
                j+=1
            else:
                while count == 0:
                    if j-i < lenght:
                        string = s[i:j]
                        lenght = j-i
                    if s[i] in  mp2:
                        mp2[s[i]]+=1
                        if mp2[s[i]] > 0:
                            count+=1
                    i+=1

        return string
                    

