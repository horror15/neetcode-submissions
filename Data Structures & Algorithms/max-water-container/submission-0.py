class Solution:
    def maxArea(self, heights: List[int]) -> int:
        i,j,volume = 0, len(heights)-1, 0
        while(i<j):
            height = min(heights[i], heights[j])
            length = j-i
            volume = max(volume, height*length)
            if heights[i] > heights[j]:
                j-=1
            elif heights[i] < heights[j]:
                i+=1
            else:
                i+=1
                j-=1
        return volume