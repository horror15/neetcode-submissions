class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        vector<bool> dp(s.size(), false);
        int max_size = INT_MIN;
        for(auto word: wordDict){
            int sz = word.size();
            max_size = max(max_size, sz);
            st.insert(word);
        }
        for(int i=0; i<s.size(); i++){
            int j = i;
            while (j>=0){
                string ss = s.substr(j, i-j+1);
                if(ss.size() > max_size) break;
                if(st.find(ss) != st.end() && (j==0 || dp[j-1] == true)){
                    dp[i] = true;
                    break;
                } 
                j--;
            }
        }
        return dp[s.size()-1];
        
    }
};
