class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(n+m != s3.size()) {
            return false;
        }
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i=1; i<n+1; i++){
            if(s3[i-1] == s1[i-1]) {
                if(dp[i-1][0] == true) {
                    dp[i][0] = true;
                }
            }
        }
        for(int j=1; j<m+1; j++){
            if(s3[j-1] == s2[j-1]){
                if(dp[0][j-1] == true){
                    dp[0][j] = true;
                }
            }
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s3[i+j-1] == s1[i-1]){
                    if(dp[i-1][j] == true) {
                        dp[i][j] = true;
                    }
                } 
                if(s3[i+j-1] == s2[j-1]) {
                    if(dp[i][j-1] == true){
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[n][m];

    }
};
