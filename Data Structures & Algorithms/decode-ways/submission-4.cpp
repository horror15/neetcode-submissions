class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        
        int n = s.size();
        // dp[i] stores the number of ways to decode a string of length i
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1; // Base case: empty string has 1 way to be "decoded"
        dp[1] = 1; // We already know s[0] isn't '0'

        for (int i = 2; i <= n; i++) {
            // Check single digit (s[i-1])
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }

            // Check two digits (s[i-2] and s[i-1])
            // We use math instead of string concatenation for speed
            int twoDigit = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
            
            // If the bridge is broken (no ways to decode), dp[i] remains 0
        }

        return dp[n];
    }
};