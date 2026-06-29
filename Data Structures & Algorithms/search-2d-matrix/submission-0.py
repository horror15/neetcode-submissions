class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for i in range(len(matrix)):
            j = 0
            k = len(matrix[0])-1
            while j<=k:
                mid = (j+k)//2
                if matrix[i][mid] > target:
                    k = mid-1
                elif matrix[i][mid] < target:
                    j = mid+1
                else:
                    return True
        return False