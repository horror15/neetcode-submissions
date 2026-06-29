class Solution:
    def mySqrt(self, x: int) -> int:
        i,j=0, x
        while i<=j:
            mid = (i+j)//2
            if (mid*mid) > x:
                j = mid-1
            elif (mid*mid) < x:
                i = mid+1
            else:
                return mid
        return j       