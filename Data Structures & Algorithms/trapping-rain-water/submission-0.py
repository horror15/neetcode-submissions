class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left = [0]*n
        right = [0]*n
        total = 0
        for i in range(1,n):
            if height[i-1] > left[i-1] :
                left[i] = height[i-1]
            else:
                left[i] = left[i-1]
        for i in range(n-2,-1,-1):
            if height[i+1] > right[i+1]:
                right[i] = height[i+1]
            else:
                right[i] = right[i+1]
        print(left)
        print(right)
        for i in range(1,n-1):
            h = min(left[i], right[i]) - height[i]
            if h>=0:
                total+=h
        return total 


