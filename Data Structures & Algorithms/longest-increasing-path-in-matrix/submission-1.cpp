class Solution {
public:

    int test(int i, int j, vector<vector<int>>& matrix, int prev, vector<vector<int>> &dp){
        if(i<0 || j<0 || i == matrix.size() || j == matrix[0].size() || matrix[i][j] <= prev) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int down = test(i+1, j, matrix, matrix[i][j], dp);
        int right = test(i, j+1, matrix,matrix[i][j], dp);
        int top = test(i-1, j, matrix, matrix[i][j], dp);
        int left = test(i, j-1, matrix, matrix[i][j], dp);

        return dp[i][j] = 1 + max({down, right, left, top});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int max_len = INT_MIN;
        int prev = INT_MIN;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                max_len = max(max_len, test(i, j, matrix, prev, dp));
            }
        }
        return max_len;
    }
};
