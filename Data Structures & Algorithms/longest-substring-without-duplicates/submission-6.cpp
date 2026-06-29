class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int i=0,j=0;
        int max_len = INT_MIN;
        while(j<s.size()){
            if(st.count(s[j])==0){
                st.insert(s[j]);
                j++;
                max_len = max(max_len, j-i);
            } else{
                while(i<j){
                    st.erase(s[i]);
                    if(s[i]==s[j]){
                        i++;
                        break;
                    }
                    i++;
                }
            }
        }
        max_len = max(max_len, j-i);
        return max_len;
    }
};
