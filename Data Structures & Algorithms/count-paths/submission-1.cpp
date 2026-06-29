class Solution {
public:
    void test(int i, int j, int m, int n, int &count){

        if(i == m-1 && j == n-1) {
            count++;
            return;
        } 
        if(i > m-1 || j > n-1) return;
        test(i+1, j, m, n, count);
        test(i, j+1, m, n, count);
    }


    int uniquePaths(int m, int n) {
        int count = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0; i<m; i++){
            dp[i][0] = 1;
        }
        for(int j =0; j<n; j++){
            dp[0][j] = 1;
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
