class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        int i=0, j=0, len = 1;
        unordered_set<char>st;
        while(j<s.size()){
            if(!st.count(s[j])){
                st.insert(s[j]);
            } else {
                if(j-i>len){
                    len = j-i;
                }
                while(s[j]!=s[i]){
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                st.insert(s[j]);
                i++;
            }
            j++;
        }
        if(st.size()>len){
            return st.size();
        } else {
            return len;
        }
    }
};
