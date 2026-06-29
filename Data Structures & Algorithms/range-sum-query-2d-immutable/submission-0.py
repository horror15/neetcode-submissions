class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix
        m = len(self.matrix)
        n = len(self.matrix[0])
        for row in range(m):
            for col in range(1,n):
                matrix[row][col] += matrix[row][col-1]
        for col in range(n):
            for row in range(1,m):
                matrix[row][col] += matrix[row-1][col]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        sum = self.matrix[row2][col2]
        if ((row1-1) >= 0):
            sum -= self.matrix[row1-1][col2]
        if ((col1-1) >= 0):
            sum -= self.matrix[row2][col1-1]
        if ((row1-1) >= 0 and (col1-1) >= 0):
            sum += self.matrix[row1-1][col1-1]

        return sum
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)