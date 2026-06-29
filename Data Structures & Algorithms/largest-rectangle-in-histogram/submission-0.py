class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        stack = []
        for i in range(len(heights)):
            start = i
            while stack and stack[-1][1] > heights[i]:
                height = stack[-1][1]
                width = i - stack[-1][0]
                max_area = max(max_area, height*width)
                start = stack[-1][0]
                stack.pop()
            stack.append((start,heights[i]))
        for i,h in stack:
            max_area = max(max_area, h * (len(heights)-i))
        return max_area
