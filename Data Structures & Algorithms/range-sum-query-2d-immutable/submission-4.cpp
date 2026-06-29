class NumMatrix {
public:
    vector<vector<int>>vec;
    NumMatrix(vector<vector<int>>& matrix) {
        vec.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for(int i=1; i<matrix.size()+1; i++){
            for(int j=1; j<matrix[0].size()+1; j++){
                vec[i][j] = matrix[i-1][j-1] + vec[i][j-1];
            }
        }
        for(int j=1; j<matrix[0].size()+1; j++){
            for(int i=1; i<matrix.size()+1; i++){
                vec[i][j] = vec[i][j] + vec[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        row2++;
        col1++;
        col2++;
        return vec[row2][col2] - vec[row1-1][col2] - vec[row2][col1-1] + vec[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */