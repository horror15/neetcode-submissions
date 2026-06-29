class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        n = len(people)
        l,r = 0,n-1
        boats=0
        while l<=r:
            if people[l] + people[r] > limit:
                r-=1
                boats+=1
            else:
                r-=1
                l+=1
                boats+=1
        return boats

